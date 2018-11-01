/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** 
*/

#include "../include/philo.h"

int	eat = 0;

void	help(void)
{
	printf("USAGE\n");
	printf("\t./philo -p nbr_p -e nbr_e\n");
	printf("\n");
	printf("DESCRIPTION\n");
	printf("\t-p nbr_p\tnumber of philosophers\n");
	printf("\t-e nbr_e\tmaximum number times a philosopher");
	printf(" eats before exiting the program\n");
}

t_info	check_nbr(char **av, int i, t_info info)
{
	int	nb = 0;
	
	if (av[i + 1] == NULL) {
		info.philo = -84;
		return info;
	}
	while (av[i + 1][nb] != '\0') {
		if (av[i + 1][nb] < '0' || av[i + 1][nb] > '9') {
			info.philo = -84;
			return info;
		}
		nb++;
	}
	if (strcmp(av[i], "-p") == 0)
		info.philo = atoi(av[i + 1]);
	else
		eat = atoi(av[i + 1]);
	return info;
}

t_info	check_arg(t_info info, char **av, int ac)
{
	int	i = 1;

	while (i != ac) {
		if (strcmp(av[i], "-p") == 0
		    || strcmp(av[i], "-e") == 0) {
			info = check_nbr(av, i, info);
			if (info.philo == -84)
				return info;
			i++;
		}
		else {
			info.philo = -84;
			if (ac == 2 && strcmp(av[1], "--help") == 0) {
				info.philo = -42;
				help();
			}
			return info;
		}
		i++;
	}
	return info;
}

int	main(int ac, char **av)
{
	t_info	info;

	info.philo = 0;
	if (ac == 1)
		return 84;
	info = check_arg(info, av, ac);
	if (info.philo == -84)
		return 84;
	if (info.philo == -42)
		return 0;
	RCFStartup(ac, av);
	start_philosopher(info);
	clean_philosopherList();
	RCFCleanup();
	return 0;
}
