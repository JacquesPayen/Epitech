/*
** EPITECH PROJECT, 2017
** libmy_malloc
** File description:
** 
*/

#include "../include/malloc.h"

block_t	malloc_list = NULL;
block_t	end_list = NULL;

// Malloc free block finding function
// size : size of the memory blocks in bytes
// return available block or NULL in case of error
block_t	find_free_block(size_t size)
{
	block_t	tmp_malloc_list;

	tmp_malloc_list = malloc_list;
	while (tmp_malloc_list) {
		if (tmp_malloc_list->free && tmp_malloc_list->size >= size)
			return tmp_malloc_list;
		tmp_malloc_list = tmp_malloc_list->next;
	}
	return NULL;
}

// Malloc block creating function
// size : size of the memory blocks in bytes
// return the new block or NULL in case of error
void	*create_block(size_t size)
{
	block_t	new_block;

	new_block = sbrk(0);
	if (sbrk(sizeof(struct block_s) + size) == (void*) - 1)
		return NULL;
	new_block->free = 0;
	new_block->size = size;
	new_block->next = NULL;
	if (end_list) {
		end_list->next = new_block;
		new_block->prev = end_list;
	}
	else {
		malloc_list = new_block;
		new_block->prev = NULL;
	}
	end_list = new_block;
	return new_block->ptr;
}

// Malloc start function
// size : size of the memory blocks in bytes
// return the new block or NULL in case of error
void	*malloc(size_t size)
{
	block_t	block;

	block = find_free_block(size);
	if (block) {
		block->free = 0;
		return block->ptr;
	}
	return create_block(size);
}
