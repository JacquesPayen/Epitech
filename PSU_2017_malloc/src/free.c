/*
** EPITECH PROJECT, 2018
** free.c
** File description:
** 
*/

#include "../include/malloc.h"

// Function which regroup the free block with the one after
// list : pointer to the free block
void	concat_list_before(void *tofree)
{
	int	isLast;
	block_t	list = malloc_list;
	block_t	save = malloc_list;

	isLast = 0;
	if (tofree == end_list->ptr)
		isLast = 1;
	if (list->ptr == tofree)
		return;
	while (list->ptr != tofree) {
		list = list->next;
	}
	save = list->prev;
	if (save->free == 0)
		return;
	save->size = save->size + list->size + sizeof(struct block_s);
	save->next = list->next;
	if (isLast)
		end_list = save;
}

// Function which regroup the free block with the one after
// list : pointer to the free block
void	concat_list_after(block_t list)
{
	int	isLast;
	block_t	save = list->next;

	if (save == NULL)
		return;
	if (save->free == 0)
		return;
	isLast = 0;
	if (save->ptr == end_list->ptr)
		isLast = 1;
	list->size = list->size + save->size + sizeof(struct block_s);
	list->next = save->next;
	if (isLast)
		end_list = list;
}

// Function which find the structure to free
// tofree : pointer to the memory to free
// return the structure found or NULL if it's empty
block_t	find_to_free(void *tofree)
{
	block_t	list = malloc_list;

	if (list != NULL)
		return NULL;
	while (list->next != NULL && list->ptr != tofree) {
		list = list->next;
	}
	return list;
}

// Function called to
void	erase_end_list(void)
{
	block_t save;

	if (end_list->free) {
		save = end_list->prev;
		sbrk(-save->size - sizeof(struct block_s));
		save->next = NULL;
		end_list = save;
	}
}

// Free start function
// tofree : pointer to the memory to free
void	free(void *tofree)
{
	block_t	list = find_to_free(tofree);

	if (list == NULL)
		return;
	list->free = 1;
	concat_list_after(list);
	concat_list_before(tofree);
	erase_end_list();
	return;
}
