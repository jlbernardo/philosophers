/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:12:55 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/11 21:07:02 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	register_guests(t_data *diner, int argc, char **argv)
{
	diner->seats = atost(argv[1]);
	diner->die_time = atost(argv[2]);
	diner->eat_time = atost(argv[3]);
	diner->sleep_time = atost(argv[4]);
	if (argc == 6)
		diner->meals_hired = atost(argv[5]);
	else
		diner->meals_hired = __SIZE_MAX__;
	pthread_mutex_init(&diner->print, NULL);
	diner->philo = malloc(diner->seats * sizeof(t_tab));
}

void	serve_tables(t_data *diner)
{
	size_t	i;

	i = 0;
	while (i < diner->seats)
	{
		pthread_mutex_init(&diner->philo[i].hashi, NULL);
		diner->philo[i].diner = diner;
		diner->philo[i].plates = 0;
		diner->philo[i].id = i;
		i++;
	}
	i = 0;
	pthread_create(&diner->waiter, NULL, &restaurant_open, (void *)diner);
	while (i < diner->seats)
	{
		pthread_create(&diner->philo[i].guest, NULL, &dinner,
			(void *)&diner->philo[i]);
		i++;
	}
}
