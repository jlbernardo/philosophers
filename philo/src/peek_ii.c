/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek_ii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:11:25 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/13 17:27:25 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	time_to_die(t_data *diner)
{
	size_t	time;

	pthread_mutex_lock(&diner->peek[TIME_TO_DIE]);
	time = diner->die_time;
	pthread_mutex_unlock(&diner->peek[TIME_TO_DIE]);
	return (time);
}

size_t	meals_hired(t_data *diner)
{
	size_t	meals;

	pthread_mutex_lock(&diner->peek[MEALS]);
	meals = diner->meals_hired;
	pthread_mutex_unlock(&diner->peek[MEALS]);
	return (meals);
}

size_t	philo_id(t_tab *philo)
{
	size_t	id;

	pthread_mutex_lock(&philo->diner->peek[PHILO_ID]);
	id = philo->id;
	pthread_mutex_unlock(&philo->diner->peek[PHILO_ID]);
	return (id);
}

size_t	philo_plates(t_tab *philo)
{
	size_t	plates;

	pthread_mutex_lock(&philo->diner->peek[PHILO_PLATES]);
	plates = philo->plates;
	pthread_mutex_unlock(&philo->diner->peek[PHILO_PLATES]);
	return (plates);
}

size_t	philo_last_meal(t_tab *philo)
{
	size_t	last_meal;

	pthread_mutex_lock(&philo->diner->peek[PHILO_LAST_MEAL]);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->diner->peek[PHILO_LAST_MEAL]);
	return (last_meal);
}
