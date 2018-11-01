/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** channel
*/

#ifndef CHANNEL_H_
	#define CHANNEL_H_

typedef struct channel_s
{
    char	*name;
    struct channel_s	*next;
} channel_t;

#endif /* !CHANNEL_H_ */
