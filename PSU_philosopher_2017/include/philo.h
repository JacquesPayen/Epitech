/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** pilo.
*/

#ifndef PHILO_H_
	#define PHILO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extern.h"

typedef struct	s_info
{
        int	philo;
        int	help;
}	t_info;


typedef struct philosopher_s	philosopher_t;
struct	philosopher_s
{
	pthread_mutex_t	chopstick;
	philosopher_t	*next;
};

extern int	eat;
extern philosopher_t	*philosopher_list;
void	*philosopher_run(void*);
void	start_philosopher(t_info);
void	clean_philosopherList();

#endif /* !PHILO_H_ */
