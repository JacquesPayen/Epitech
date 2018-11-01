/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** cmd
*/

#include "../server_include/irc.h"

void	cmd(client_t *client_list, buf_t *buf)
{
	char	**tab;
	int	fd;
	char	*str;

	str = buf_get(buf);
	printf("%s\n", str);
	fflush(stdout);
	/*
	tab = my_str_to_wordtab(str, " ");
	fd = atoi(tab[0]);
	str = tab[1];
	for (int i = 0 ; tab[i] ; i++) {
		printf("Line : %s\n", tab[i]);
	}
	printf("END str : %s\n", str);
	fflush(stdout);
	if (strncmp(str, "NICK", 4) == 0)
		nickname(client_list, tab, fd);
	if (strncmp(str, "PASS", 4) == 0)
		password(client_list, tab, fd);
	if (strncmp(str, "USER", 4) == 0)
		username(client_list, tab, fd);
	//if (strncmp(str, "JOIN", 5) == 0)
		//
	//if (strncmp(str, "PRIVMSG", 7) == 0)
		//
	*/
}
