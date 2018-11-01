/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** tools
*/

#include "../server_include/irc.h"

int	get_tokens_count(char *str, char *s)
{
	int	count = 0;

	for (int i = 0 ; str[i] ; i++) {
		for (int j = 0 ; s[j] ; j++) {
			if (str[i] == s[j])
				count++;
		}
	}
	return count;
}

char	**my_str_to_wordtab(char *str, char *s)
{
	int	i = 0;
	char	**tab;
	char	*tmp;
	char	*token;

	tab = malloc(sizeof(char*) * (get_tokens_count(str, s) + 2));
	tmp = strdup(str);
	while ((token = strsep(&tmp, s)) != NULL) {
		tab[i] = strdup(token);
		i++;
	}
	tab[i] = NULL;
	return tab;
}

void	free_tab(char **tab)
{
	for (int i = 0 ; tab[i] ; i++)
		free(tab[i]);
	free(tab);
}

int	get_tab_len(char **tab)
{
	int	i = 0;

	while (tab[i])
		i++;
	return i;
}