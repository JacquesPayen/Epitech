/*
** EPITECH PROJECT, 2018
** ftp
** File description:
** main
*/

#include "../include/my.h"

char	*get_cmd(char *str)
{
	char	*cmd;
	char	*save;

	save = malloc(sizeof(int) * 128);
	memcpy(save, str, 128);
	cmd = strsep(&save, " ");
	if (save == NULL)
		cmd = strsep(&cmd, "\n");
	return (cmd);
}

char	*get_arg(char *str)
{
	char	*arg = NULL;
	char	*save;

	save = malloc(sizeof(int) * 128);
	memcpy(save, str, 128);
	strsep(&save, " ");
	if (save != NULL)
		arg = strsep(&save, "\n");
	return (arg);
}

int	my_com_manage(char *str, server_t *server, int fd)
{
	char		*arg;
	char		*cmd;
	int		i = 0;
	int		limit = 0;

	cmd = get_cmd(str);
	arg = get_arg(str);
	fflush(stdout);
	while (list[i].name != NULL && strcmp(list[i].name, cmd) != 0)
		i += 1;
	if (list[i].name != NULL)
		limit = list[i].function(arg, fd, server) - 1;
	else
		dprintf(fd, "ko\n");
	return (limit);
}

void	exec_request(server_t *server)
{
	player_t	*pt = server->player;
	buff_t	*buff;	

	while (pt != NULL) {
		buff = pt->cmd;
		if (buff->timer == buff->limit) {
			buff->timer = 0;
			buff->limit = 0;
			if (buff->r < buff->w) {
				buff->limit = my_com_manage(buff->data[buff->r % 10], server, pt->fd);
				buff->r += 1;
			}	
		}
		else
			buff->timer += 1;
		pt = pt->next;
	}
}