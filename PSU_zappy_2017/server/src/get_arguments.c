/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../include/my.h"

int	create_team(server_t *server, char **av, int i)
{	
	int	j = i + 1;
	team_t	*pt = server->team;
	team_t	*save;

	while (av[j][0] != '-') {
		pt->name = av[j];
		pt->nb_player = 0;
		pt->max_player = 0;
		pt->next = malloc(sizeof(team_t));
		save = pt;
		pt = pt->next;
		j += 1;
	}
	if (j == i + 1)
		my_help();
	save->next = NULL;
	free(pt);
	server->fd = j - (i + 1);
	return (j - 2);
}

void	fill_team(server_t *server, int nb)
{
	team_t	*pt = server->team;

	while (pt != NULL) {
		pt->max_player = nb;
		pt = pt->next;
	}
}

int	check_arg(char **av, int i, server_t *server)
{
	if (av[i][0] != '-')
		my_help();
	else if (av[i][1] == 'p')
		server->port = atoi(av[i + 1]);
	else if (av[i][1] == 'x')
		server->map->width = atoi(av[i + 1]);
	else if (av[i][1] == 'y')
		server->map->height = atoi(av[i + 1]);
	else if (av[i][1] == 'n')
		i = create_team(server, av, i);
	else if (av[i][1] == 'f')
		server->freq = atoi(av[i + 1]);
	return (i);
}

server_t	*create_server(int ac, char **av)
{
	server_t	*server = malloc(sizeof(server_t));
	int		nb;

	server->player = NULL;
	server->egg = NULL;
	server->map = malloc(sizeof(map_t));
	server->team = malloc(sizeof(team_t));
	for (int i = 1; i < ac; i += 2) {
		if (av[i][1] == 'c')
			nb = atoi(av[i + 1]);
		else
			i = check_arg(av, i, server);
	}
	if (ac != server->fd + 12)
		my_help();
	fill_team(server, nb);
	server->fd = my_setup();
	server_pt = server;
	return (server);
}

char	*clean_buff(char *buff)
{
	int	i = 0;
	char	*str;

	while ((buff[i] >= '0' && buff[i] <= '9') || 
		(buff[i] >= 'a' && buff[i] <= 'z') ||
		(buff[i] >= 'A' && buff[i] <= 'Z') ||
		buff[i] == '_' || buff[i] == '.')
		i += 1;
	str = malloc(sizeof(char) * (i + 1));
	strncpy(str, buff, i);
	str[i] = '\0';
	return (str);
}