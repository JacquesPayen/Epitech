/*
** EPITECH PROJECT, 2018
** simple.c
** File description:
** 
*/

#include <stdio.h>
#include <criterion/criterion.h>

Test(utils, little_malloc)
{
	char	*str = malloc(sizeof(char) * 3);

	strcpy(str, "str");
	cr_assert(strcmp(str, "str") == 0);
}

Test(utils, little_malloc_free)
{
	void	*a = malloc(sizeof(char) * 3);
	void	*b;
	
	free(a);
	b = malloc(sizeof(char) * 3);
	cr_assert(a == b);
}

Test(utils, medium_malloc_free)
{
	int	*nb = malloc(sizeof(char) * 100000000);
	int	i = 100000000;
	
	*nb = 100000000;
	cr_assert(*nb == i);
}

Test(utils, medium_malloc)
{
	void	*nb = malloc(sizeof(char) * 100000000);
	void	*i;

	free(nb);
	i = malloc(sizeof(char) * 100000000);
	cr_assert(nb == i);
}


Test(utils, little_realloc_null)
{
	char	*str = realloc(NULL, sizeof(char) * 3);
	
	strcpy(str, "str");
	cr_assert(strcmp(str, "str") == 0);
}

Test(utils, little_malloc_realloc_empty)
{
	char	*res = malloc(sizeof(char) * 3);

	res = realloc(res, sizeof(char) * 3);
	res = strcpy(res, "loltes");
	cr_assert(strcmp(res, "loltes") == 0);
}

Test(utils, little_malloc_realloc)
{
	char	*str = malloc(sizeof(char) * 3);
	char	*res;

	strcpy(str, "str");
	res = realloc(str, sizeof(char) * 3);
	res = strcat(res, "lol");
	cr_assert(strcmp(res, "strlol") == 0);
}

Test(utils, little_realloc_free)
{
	void	*res = realloc(NULL, sizeof(char) * 3);
	void	*adr;

	free(res);
	adr = realloc(NULL, sizeof(char) * 3);
	cr_assert(adr = res);
}
