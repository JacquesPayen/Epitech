/*
** EPITECH PROJECT, 2018
** ftp
** File description:
** main
*/

#include "../include/my.h"

int	login_client(team_t *pt, server_t *serv, int new)
{
	if (pt == NULL || pt->nb_player >= pt->max_player) {
		printf("[-] Disconnection: %d\n", new);
		dprintf(new, "ko\n");
		return (0);
	}
	pt->nb_player += 1;
	dprintf(new, "%d\n", pt->max_player - pt->nb_player);
	dprintf(new, "%d %d\n", serv->map->width, serv->map->height);
	create_player(new, serv, pt->name);
	return (1);
}

int	new_client(server_t *serv)
{
	int	new;
	int	len = 0;
	char	buff[128];
	team_t	*pt = serv->team;

	new = accept(serv->fd, NULL, NULL);
	if (new < 0)
		my_exit("ERROR : accept failed\n", serv->fd, -1, 84);
	printf("[+] New incoming connection: %d\n", new);
	dprintf(new, "WELCOME\n");
	while (len == 0)
		len = read(new, buff, 128);
	while (pt != NULL && strcmp(pt->name, clean_buff(buff)) != 0)
		pt = pt->next;
	if (login_client(pt, serv, new) == 0)
		return (0);
	return (1);
}

int	fd_exec(int fd, server_t *serv, int nb_fd)
{
	player_t	*pt;
	int		i;

	nb_fd -= 1;
	if (fd == serv->fd)
		new_client(serv);
	else
		get_request(fd, serv);
	return (nb_fd);
}

void	my_select_loop(server_t *serv)
{
	int		max = 0;
	int		nb_fd = 0;
	struct timeval 	timeout;
	int		i = 0;

	timeout.tv_sec  = 0;
	timeout.tv_usec = 100;
	max = set_readfds(serv);
	nb_fd = select(max, &(serv->ref_set), NULL, NULL, &timeout);
	if (nb_fd < 0)
		my_exit("ERROR : select failed\n", serv->fd, -1, 84);
	while (i < (max + 1) && nb_fd > 0) {
		if (FD_ISSET(i, &(serv->ref_set)))
			nb_fd = fd_exec(i, serv, nb_fd);
		i += 1;
	}
}

int	main(int ac, char **av)
{
	server_t	*serv;
	t_graphic	graph;
	char		*winner = NULL;

	serv = create_server(ac, av);
	my_setup_connection(serv->fd, serv->port);
	serv->map->map = generation_map(serv->map->height, serv->map->width);
	graph = init_graphic(graph, serv->map->map,
		serv->map->height, serv->map->width);
	while ((winner = my_win(serv)) == NULL) {
		my_select_loop(serv);
		exec_request(serv);
		my_death(serv);
		my_hatching(serv);
		SDL_PollEvent(&graph.event);
		graph = run_graphic(graph, serv->player);
		usleep(1000000 / serv->freq);
		}
	leave_sdl(graph);
	printf("[!] %s win the game", winner);
	close_server(serv);
	return (0);
}
