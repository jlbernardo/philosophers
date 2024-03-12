/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:54:01 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/11 21:05:06 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *philo_tab)
{
	t_tab	*philo;

	philo = (t_tab *)philo_tab;
	usleep(100);
	while (restaurant_open(philo->diner))
	{
		pthread_mutex_unlock(&philo->diner->print);
		eat(philo);
		nap(philo);
		think(philo);
	}
	return (philo_tab);
}

void	close_diner(t_data *diner)
{
	size_t	i;

	i = 0;
	while (i < diner->seats)
	{
		pthread_join(diner->philo[i].guest, NULL);
		i++;
	}
	i = 0;
	while (i < diner->seats)
	{
		pthread_mutex_destroy(&diner->philo[i].hashi);
		i++;
	}
	pthread_mutex_destroy(&diner->print);
	free(diner->philo);
}
