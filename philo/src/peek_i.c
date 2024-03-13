/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:11:13 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/12 22:21:49 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	diner_open(t_data *diner)
{
	bool	open;

	pthread_mutex_lock(&diner->peek[OPEN]);
	open = diner->open;
	pthread_mutex_unlock(&diner->peek[OPEN]);
	return (open);
}

size_t	simulation_time(t_data *diner)
{
	size_t			simulation;
	struct timeval	time;

	gettimeofday(&time, NULL);
	simulation = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	pthread_mutex_lock(&diner->peek[START]);
	simulation -= diner->start;
	pthread_mutex_unlock(&diner->peek[START]);
	return (simulation);
}

size_t	seats_taken(t_data *diner)
{
	size_t	seats;

	pthread_mutex_lock(&diner->peek[SEATS]);
	seats = diner->seats;
	pthread_mutex_unlock(&diner->peek[SEATS]);
	return (seats);
}

size_t	time_to_eat(t_data *diner)
{
	size_t	time;

	pthread_mutex_lock(&diner->peek[TIME_TO_EAT]);
	time = diner->eat_time;
	pthread_mutex_unlock(&diner->peek[TIME_TO_EAT]);
	return (time);
}

size_t	time_to_sleep(t_data *diner)
{
	size_t	time;

	pthread_mutex_lock(&diner->peek[TIME_TO_SLEEP]);
	time = diner->sleep_time;
	pthread_mutex_unlock(&diner->peek[TIME_TO_SLEEP]);
	return (time);
}
