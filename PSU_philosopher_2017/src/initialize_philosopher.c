/*
** EPITECH PROJECT, 2018
** Philosopher
** File description:
** initializePhilosopher
*/

#include "../include/philo.h"

philosopher_t	*philosopher_list = NULL;

void	clean_philosopherList(void)
{
	philosopher_t	*tmp_philosopher;

	while (philosopher_list) {
		tmp_philosopher = philosopher_list;
		philosopher_list = philosopher_list->next;
		pthread_mutex_destroy(&tmp_philosopher->chopstick);
		free(tmp_philosopher);
	}
}

void	add_philosopher(void)
{
	philosopher_t	*new_philosopher;
	philosopher_t	*tmp_philosopher;

	new_philosopher = malloc(sizeof(philosopher_t));
	if (new_philosopher == NULL)
		exit(84);
	if (pthread_mutex_init(&new_philosopher->chopstick, NULL))
		exit(84);
	new_philosopher->next = NULL;
	if (philosopher_list == NULL)
		philosopher_list = new_philosopher;
	else {
		tmp_philosopher = philosopher_list;
		while (tmp_philosopher->next)
			tmp_philosopher = tmp_philosopher->next;
		tmp_philosopher->next = new_philosopher;
	}
}

void	start_philosopher(t_info info)
{
	philosopher_t	*tmp_philosopher;
	pthread_t	threads[info.philo];

	for (int i = 0 ; i < info.philo ; i++)
		add_philosopher();
	tmp_philosopher = philosopher_list;
	for (int j = 0 ; tmp_philosopher ; j++) {
		if (pthread_create(&threads[j], NULL,
				   philosopher_run, (void*)tmp_philosopher))
			exit(84);
		tmp_philosopher = tmp_philosopher->next;
	}
	for (int k = 0 ; k < info.philo ; k++)
		pthread_join(threads[k], NULL);
}
