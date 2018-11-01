OB/*
** get_next_line.c for get_next_line.c in /home/jacques/CPE_2016_getnextline
**
** Made by Jacques Payen
** Login   <jacques.payen@epitech.eu@epitech.net>
**
** Started on  Sat Jan  7 18:13:03 2017 Jacques Payen
** Last update Fri Jan 13 19:37:28 2017 Jacques Payen
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	my_strlen(char * str)
{
  int	i;

  i  = 0;
  while (str[i] != '\0' && str[i] != '\n')
    i++;
  return (i);
}

char    *my_strncpy(char *dest, char *src, int n)
{
  int   i;

  if (n == 0)
    return (dest);
  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

int	strcomp(char *buffer, char **text, int *nb_readded)
{
  char	*str;
  int	len;
  int	buflen;

  len = 0;
  if (*text != NULL)
      len = my_strlen(*text);
  buflen = my_strlen(&buffer[*nb_readded]);
  if ((str = malloc(sizeof(char) * (len + buflen + 1))) == NULL)
    return (-1);
  my_strncpy(str, *text, len);
  my_strncpy(&str[len], &buffer[*nb_readded], buflen);
  *text = str;
  *nb_readded = *nb_readded + buflen;
  if (buffer[*nb_readded] == '\n')
    {
      *nb_readded = *nb_readded + 1;
      return (0);
    }
  else
    return (1);
}

char	*get_next_line(const int fd)
{
  static int	nb_in_buff = 0;
  static int	nb_readded = 0;
  char*	text;
  int	i;
  static char	buffer[READ_SIZE + 1];

  text = NULL;
  while (1)
    {
      if (nb_in_buff == nb_readded)
	{
	  nb_readded = 0;
	  if ((nb_in_buff = read(fd, buffer, READ_SIZE)) <= 0)
	    return (text);
	}
      i = strcomp(buffer, &text, &nb_readded);
      if (i == -1)
	return (NULL);
      if (i == 0)
	return (text);
    }
}
