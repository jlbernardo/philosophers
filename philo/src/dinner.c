/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:54:01 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/12 23:26:38 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *philo_tab)
{
	t_tab	*philo;

	philo = (t_tab *)philo_tab;
	if (seats_taken(philo->diner) == 1)
		return (philo_tab);
	while (diner_open(philo->diner))
	{
		eat(philo);
		nap(philo);
		think(philo);
	}
	return (philo_tab);
}

void	close_diner(t_data *diner)
{
	size_t	i;
	size_t	seats;

	i = -1;
	seats = seats_taken(diner);
	pthread_join(diner->waiter, NULL);
	while (++i < seats)
		pthread_join(diner->philo[i].guest, NULL);
	i = -1;
	while (++i < seats)
		pthread_mutex_destroy(&diner->philo[i].hashi);
	i = -1;
	while (++i < TOTAL_MUTEXES)
		pthread_mutex_destroy(&diner->peek[i]);
	pthread_mutex_destroy(&diner->print);
	free(diner->philo);
}
