/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** buffer
*/

#include "../server_include/irc.h"

void	buf_reset(buf_t *buf)
{
	if (buf) {
		buf->head = 0;
		buf->tail = 0;
	}
}

void	buf_put(buf_t *buf, char *data)
{
	//check if length <= 512
	if (buf) {
		buf->buffer[buf->head] = strdup(data);
		buf->head = buf->head + 1;
		if (buf->head >= buf->size)
			buf->head = 0;
	}
}

char	*buf_get(buf_t *buf)
{
	char	*str;

	if (buf && buf->buffer[buf->tail]) {
		str = buf->buffer[buf->tail];
		buf->buffer[buf->tail] = NULL;
		buf->tail = buf->tail + 1;
		return str;
	}
	return NULL;
}