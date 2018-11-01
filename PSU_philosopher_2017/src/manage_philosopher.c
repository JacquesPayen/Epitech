/*
** EPITECH PROJECT, 2018
** Philosopher
** File description:
** managePhilosopher
*/

#include "../include/philo.h"

void	philo_think(void)
{
	lphilo_think();
}

void	philo_eat(philosopher_t *philosopher)
{
	if (philosopher->next) {
		while (pthread_mutex_trylock(&philosopher->next->chopstick) == 0);
		lphilo_take_chopstick(&philosopher->next->chopstick);
		lphilo_eat();
		lphilo_release_chopstick(&philosopher->next->chopstick);
		pthread_mutex_unlock(&philosopher->next->chopstick);
	}
	else {
		while (pthread_mutex_trylock(&philosopher_list->chopstick) == 0);
		lphilo_take_chopstick(&philosopher_list->chopstick);
		lphilo_eat();
		lphilo_release_chopstick(&philosopher_list->chopstick);
		pthread_mutex_unlock(&philosopher_list->chopstick);
	}
}

void	philo_sleep(philosopher_t *philosopher)
{
	lphilo_release_chopstick(&philosopher->chopstick);
	pthread_mutex_unlock(&philosopher->chopstick);
	lphilo_sleep();
	while (pthread_mutex_trylock(&philosopher->chopstick) == 0);
	lphilo_take_chopstick(&philosopher->chopstick);
}

void	*philosopher_run(void *vphilosopher)
{
	philosopher_t	*philosopher;
	
	philosopher = (philosopher_t*)vphilosopher;
	pthread_mutex_trylock(&philosopher->chopstick);
	lphilo_take_chopstick(&philosopher->chopstick);
	for (int i = 0; i < eat ; i++) {
		philo_think();
		philo_eat(philosopher);
		philo_sleep(philosopher);
	}
	lphilo_release_chopstick(&philosopher->chopstick);
	pthread_mutex_unlock(&philosopher->chopstick);
	pthread_exit(NULL);
}
