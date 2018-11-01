/*
** EPITECH PROJECT, 2017
** libmy_malloc
** File description:
** 
*/

#include "../include/malloc.h"



//Show allocated memory function
void	show_alloc_mem(void)
{
	block_t	tmp_malloc_list;

	printf("break : %p\n", sbrk(0));
	tmp_malloc_list = malloc_list;
	while (tmp_malloc_list)
	{
		printf("%p - %p : %zd bytes\n", tmp_malloc_list->ptr,
		tmp_malloc_list->ptr + tmp_malloc_list->size,
		tmp_malloc_list->size);
		tmp_malloc_list = tmp_malloc_list->next;
	}
}