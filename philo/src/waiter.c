/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:43:08 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/13 17:28:19 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*restaurant_open(void *data)
{
	size_t	seats;
	size_t	meals;
	t_data	*diner;

	diner = (t_data *)data;
	seats = seats_taken(diner);
	meals = meals_hired(diner);
	while (nobody_died(diner, seats))
	{
		if (meals != __SIZE_MAX__
			&& full_guests(diner, meals, seats) == seats)
			break ;
	}
	pthread_mutex_lock(&diner->peek[OPEN]);
	diner->open = false;
	pthread_mutex_unlock(&diner->peek[OPEN]);
	return (NULL);
}

bool	nobody_died(t_data *diner, size_t seats)
{
	size_t	i;

	i = -1;
	while (++i < seats)
	{
		if (simulation_time(diner) - philo_last_meal(&diner->philo[i])
			>= time_to_die(diner))
		{
			print_state(DEAD, &diner->philo[i]);
			return (false);
		}
	}
	return (true);
}

size_t	full_guests(t_data *diner, size_t meals, size_t seats)
{
	size_t	i;
	size_t	full_philos;

	i = -1;
	full_philos = 0;
	while (++i < seats)
	{
		if (philo_plates(&diner->philo[i]) >= meals)
			full_philos++;
	}
	return (full_philos);
}
