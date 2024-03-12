/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:04:42 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/11 21:05:06 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_tab *philo)
{
	grab_hashis(philo);
	print_state(EAT, philo);
	pthread_mutex_lock(&philo->diner->print);
	philo->plates++;
	pthread_mutex_unlock(&philo->diner->print);
	drop_hashis(philo);
}

void	nap(t_tab *philo)
{
	size_t	time;

	print_state(SLEEP, philo);
	pthread_mutex_lock(&philo->diner->print);
	time = philo->diner->sleep_time;
	pthread_mutex_unlock(&philo->diner->print);
	usleep(10000 * philo->diner->sleep_time);
}

void	think(t_tab *philo)
{
	print_state(THINK, philo);
}

void	grab_hashis(t_tab *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->hashi);
		print_state(GRAB, philo);
		if (philo->id != philo->diner->seats)
			pthread_mutex_lock(&philo->diner->philo[philo->id + 1].hashi);
		else
			pthread_mutex_lock(&philo->diner->philo[0].hashi);
		print_state(GRAB, philo);
	}
	else
	{
		if (philo->id != philo->diner->seats)
			pthread_mutex_lock(&philo->diner->philo[philo->id + 1].hashi);
		else
			pthread_mutex_lock(&philo->diner->philo[0].hashi);
		print_state(GRAB, philo);
		pthread_mutex_lock(&philo->hashi);
		print_state(GRAB, philo);
	}
}

void	drop_hashis(t_tab *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->hashi);
		if (philo->id != philo->diner->seats)
			pthread_mutex_unlock(&philo->diner->philo[philo->id + 1].hashi);
		else
			pthread_mutex_unlock(&philo->diner->philo[0].hashi);
	}
	else
	{
		if (philo->id != philo->diner->seats)
			pthread_mutex_unlock(&philo->diner->philo[philo->id + 1].hashi);
		else
			pthread_mutex_unlock(&philo->diner->philo[0].hashi);
		pthread_mutex_unlock(&philo->hashi);
	}
}
