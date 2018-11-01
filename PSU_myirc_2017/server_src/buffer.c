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
		buf->buffer[buf->head] = data;
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

/*
int	main()
{
	buf_t	buf;
	char	*str;

	buf.size = 1024;
	buf.buffer = malloc(sizeof(char*) * buf.size);
	buf_reset(&buf);
	buf_put(&buf, strdup("Test 1 - lol je ne pense pas\n"));
	str = buf_get(&buf);
	if (str != NULL)
		printf("%s", str);
	buf_put(&buf, strdup("Test 2 - lol ca me fais chier\n"));
	str = buf_get(&buf);
	if (str != NULL)
		printf("%s", str);
	str = buf_get(&buf);
	if (str != NULL)
		printf("%s", str);
}
*/