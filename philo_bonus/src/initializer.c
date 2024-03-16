/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:46:37 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/15 21:36:24 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	register_guests(t_data *diner, int argc, char **argv)
{
	if (argc == 6)
		diner->meals_hired = atost(argv[5]);
	else
		diner->meals_hired = __SIZE_MAX__;
	diner->open = true;
	sem_unlink("/hashi");
	sem_unlink("/print");
	diner->seats = atost(argv[1]);
	diner->die_time = atost(argv[2]);
	diner->eat_time = atost(argv[3]);
	diner->sleep_time = atost(argv[4]);
	diner->pid = malloc(diner->seats * sizeof(int));
	diner->print = sem_open("/print", O_CREAT | O_RDWR, 0666, 1);
	diner->hashi = sem_open("/hashi", O_CREAT | O_RDWR, 0666, diner->seats);
}

void	serve_tables(t_data *diner)
{
	size_t			i;
	struct timeval	time;

	i = -1;
	print_header();
	gettimeofday(&time, NULL);
	diner->start = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	while (++i < diner->seats)
	{
		diner->pid[i] = fork();
		if (diner->pid[i] == 0)
		{
			free(diner->pid);
			diner->philo.id = i;
			diner->philo.plates = 0;
			diner->philo.last_meal = 0;
			dinner(diner);
		}
	}
}

void	print_header(void)
{
	printf("┌────────────────────────────────────┐\n");
	printf("│ TIME    ID           ACTION        │\n");
	printf("├────────────────────────────────────┤\n");
}
