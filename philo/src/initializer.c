/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:12:55 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/13 15:52:47 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	register_guests(t_data *diner, int argc, char **argv)
{
	int	i;

	diner->seats = atost(argv[1]);
	diner->die_time = atost(argv[2]);
	diner->eat_time = atost(argv[3]);
	diner->sleep_time = atost(argv[4]);
	if (argc == 6)
		diner->meals_hired = atost(argv[5]);
	else
		diner->meals_hired = __SIZE_MAX__;
	diner->open = true;
	pthread_mutex_init(&diner->print, NULL);
	i = -1;
	while (++i < TOTAL_MUTEXES)
		pthread_mutex_init(&diner->peek[i], NULL);
	diner->philo = malloc(diner->seats * sizeof(t_tab));
}

void	serve_tables(t_data *diner)
{
	size_t			i;
	size_t			seats;
	struct timeval	time;

	i = -1;
	seats = diner->seats;
	while (++i < seats)
	{
		pthread_mutex_init(&diner->philo[i].hashi, NULL);
		diner->philo[i].last_meal = 0;
		diner->philo[i].diner = diner;
		diner->philo[i].plates = 0;
		diner->philo[i].id = i;
	}
	i = -1;
	print_header();
	gettimeofday(&time, NULL);
	diner->start = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	pthread_create(&diner->waiter, NULL, &restaurant_open, (void *)diner);
	while (++i < seats)
	{
		pthread_create(&diner->philo[i].guest, NULL, &dinner,
			(void *)&diner->philo[i]);
	}
}

void	print_header(void)
{
	printf("┌────────────────────────────────────┐\n");
	printf("│ TIME    ID           ACTION        │\n");
	printf("├────────────────────────────────────┤\n");
}
