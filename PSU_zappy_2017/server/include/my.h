/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include "./graphic.h"
#include "./map.h"

typedef struct	buff_s
{
	char	data[10][128];
	int	r;
	int	w;
	int	timer;
	int	limit;
}	buff_t;

typedef struct	egg_s
{
	char	*team;
	int	x;
	int	y;
	int	timer;
	struct egg_s	*next;
}	egg_t;

typedef struct	player_s
{
	int		fd;
	char		*team;
	int		x;
	int		y;
	int		dir;
	int		lvl;
	int		food;
	int		inv[7];
	buff_t		*cmd;
	struct player_s	*next;
}	player_t;

typedef struct	team_s
{
	char		*name;
	int		max_player;
	int		nb_player;
	struct team_s	*next;
}	team_t;

typedef struct	map_s
{
	int	***map;
	int	width;
	int	height;
}	map_t;

typedef struct	server_s
{
	int		fd;
	int		port;
	int		freq;
	fd_set		ref_set;
	egg_t		*egg;
	player_t	*player;
	team_t		*team;
	map_t		*map;
	t_graphic	*graphic;
}	server_t;

typedef	struct	command_s
{
	char	*name;
	int	(* function)(char *, int, server_t *);
}	commande_t;

int	my_forward(char *str, int fd, server_t *server);
int	my_right(char *str, int fd, server_t *server);
int	my_left(char *str, int fd, server_t *server);
int	my_look(char *str, int fd, server_t *server);
int	my_inventory(char *str, int fd, server_t *server);
int	my_broadcast(char *str, int fd, server_t *server);
int	my_connect_nbr(char *str, int fd, server_t *server);
int	my_fork(char *str, int fd, server_t *server);
int	my_eject(char *str, int fd, server_t *server);
int	my_take(char *str, int fd, server_t *server);
int	my_set(char *str, int fd, server_t *server);
int	my_incantation(char *str, int fd, server_t *server);

static server_t	*server_pt;	

static const char	object[7][10] = {
	{"food"},
	{"linemate"},
	{"deraumere"},
	{"sibur"},
	{"mendiane"},
	{"phiras"},
	{"thystame"},
};

static const commande_t list[] = {
	{"Forward", &my_forward},
	{"Right", &my_right},
	{"Left", &my_left},
	{"Look", &my_look},
	{"Inventory", &my_inventory},
	{"Brocast", &my_broadcast},
	{"Connect_nbr", &my_connect_nbr},
	{"Fork", &my_fork},
	{"Eject", &my_eject},
	{"Take", &my_take},
	{"Set", &my_set},
	{"Incantation", &my_incantation},
	{NULL, NULL}
};

int	my_setup();
int	my_setup_connection(int, int);
void	create_player(int, server_t *, char *);
void	my_exit(char *, int, int, int);
int	my_com_manage(char *, server_t *, int);
int	my_message(char *, int, server_t *);
void	get_request(int, server_t *);
int	set_readfds(server_t *);
void	exec_request(server_t *);
int	my_help();
server_t	*create_server(int, char **);
char	*clean_buff(char *);
t_graphic	run_graphic(t_graphic, player_t *);
t_graphic	draw_character(t_graphic, player_t *);
t_graphic	draw_character_low(t_graphic, player_t *);
int     get_sound_tile(player_t *, player_t *, map_t *);
int     find_case(int, int, int, int);
int	choose_dir(int, int, int);
int     rotatey(int, int, int, int);
int     rotatex(int, int, int, int);
void	my_hatching(server_t *);
char	*my_win(server_t *);
void	my_death(server_t *);
void	close_server(server_t *);
void	delete_team(server_t *, char *);
void	delete_client(server_t *, int);
void	delete_map(server_t *);
void	leave_sdl(t_graphic);
void	sig_handler(int);
int     level_1(server_t *, player_t *);
int     level_2(server_t *, player_t *);
int     level_3(server_t *, player_t *);
int     level_4(server_t *, player_t *);
int     level_5(server_t *, player_t *);
int     level_6(server_t *, player_t *);
int     level_7(server_t *, player_t *);
int     require_player(server_t *, player_t *, int, int);
void    elevate_player(server_t *, int, int);
int     choose_level(server_t *, player_t *);

#endif /* !MY_H_ */
