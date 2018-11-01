/*
** EPITECH PROJECT, 2017
** libmy_malloc
** File description:
** 
*/

#ifndef MALLOC_H_
	#define MALLOC_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct block_s	*block_t;
struct	block_s
{
	size_t	size;
	int	free;
	block_t	next;
	block_t	prev;
	char	ptr[1];
};

extern block_t	malloc_list;
extern block_t	end_list;

#endif /* !MALLOC_H_ */
