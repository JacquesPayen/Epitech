/*
** EPITECH PROJECT, 2017
** libmy_malloc
** File description:
** 
*/

#include "../include/malloc.h"

// Function which find if a unused memory block has enough space
// ptr : pointer to the memory to realloc
// return available block or NULL if none are availabe
block_t	find_block(void *ptr)
{
	block_t	list = malloc_list;

	while (list != NULL && list->ptr != ptr) {
		list = list->next;
	}
	return list;
}

// Realloc start function
// ptr : pointer to the memory to realloc
// size : size of the memory new blocks in bytes
// return the new block or NULL in case of error
void	*realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	block_t	block;

	block = find_block(ptr);
	if (block == NULL)
		return NULL;
	new_ptr = malloc(block->size + size);
	memcpy(new_ptr, block->ptr, block->size);
	free(ptr);
	return new_ptr;
}