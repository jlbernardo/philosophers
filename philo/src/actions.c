/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:04:42 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/13 15:38:42 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_tab *philo)
{
	size_t	eat;

	if (!diner_open(philo->diner))
		return ;
	eat = time_to_eat(philo->diner);
	grab_hashis(philo);
	pthread_mutex_lock(&philo->diner->peek[PHILO_LAST_MEAL]);
	philo->last_meal = print_state(EAT, philo);
	pthread_mutex_unlock(&philo->diner->peek[PHILO_LAST_MEAL]);
	usleep(eat * 1000);
	pthread_mutex_lock(&philo->diner->peek[PHILO_PLATES]);
	philo->plates++;
	pthread_mutex_unlock(&philo->diner->peek[PHILO_PLATES]);
	drop_hashis(philo);
}

void	nap(t_tab *philo)
{
	size_t	sleep;

	if (!diner_open(philo->diner))
		return ;
	sleep = time_to_sleep(philo->diner);
	print_state(SLEEP, philo);
	usleep(sleep * 1000);
}

void	think(t_tab *philo)
{
	if (!diner_open(philo->diner))
		return ;
	print_state(THINK, philo);
	usleep(1000);
}

void	grab_hashis(t_tab *philo)
{
	size_t	last;
	size_t	id;

	if (!diner_open(philo->diner))
		return ;
	id = philo_id(philo);
	last = seats_taken(philo->diner) - 1;
	if (id % 2 == 0)
	{
		pthread_mutex_lock(&philo->hashi);
		if (id != last)
			pthread_mutex_lock(&philo->diner->philo[id + 1].hashi);
		else
			pthread_mutex_lock(&philo->diner->philo[0].hashi);
	}
	else
	{
		if (id != last)
			pthread_mutex_lock(&philo->diner->philo[id + 1].hashi);
		else
			pthread_mutex_lock(&philo->diner->philo[0].hashi);
		pthread_mutex_lock(&philo->hashi);
	}
	print_state(GRAB, philo);
	print_state(GRAB, philo);
}

void	drop_hashis(t_tab *philo)
{
	size_t	last;

	last = seats_taken(philo->diner) - 1;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->hashi);
		if (philo->id != last)
			pthread_mutex_unlock(&philo->diner->philo[philo->id + 1].hashi);
		else
			pthread_mutex_unlock(&philo->diner->philo[0].hashi);
	}
	else
	{
		if (philo->id != last)
			pthread_mutex_unlock(&philo->diner->philo[philo->id + 1].hashi);
		else
			pthread_mutex_unlock(&philo->diner->philo[0].hashi);
		pthread_mutex_unlock(&philo->hashi);
	}
}
