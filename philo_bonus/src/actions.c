/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:08:33 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/18 20:49:38 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_data *diner)
{
	sem_wait(diner->hashi);
	sem_wait(diner->hashi);
	print_state(GRAB, diner);
	print_state(GRAB, diner);
	what_am_i_feeling(diner);
	diner->philo.last_meal = print_state(EAT, diner);
	act(diner, diner->eat_time);
	diner->philo.plates++;
	sem_post(diner->hashi);
	sem_post(diner->hashi);
}

void	nap(t_data *diner)
{
	print_state(SLEEP, diner);
	what_am_i_feeling(diner);
	act(diner, diner->sleep_time);
}

void	think(t_data *diner)
{
	print_state(THINK, diner);
	what_am_i_feeling(diner);
	act(diner, 1);
	while (*(int *)(diner->hashi) < 2)
		what_am_i_feeling(diner);
}

void	what_am_i_feeling(t_data *diner)
{
	if (simulation_time(diner) - diner->philo.last_meal >= diner->die_time)
	{
		print_state(DEAD, diner);
		sem_close(diner->print);
		sem_close(diner->hashi);
		exit(EXIT_FAILURE);
	}
	if (diner->meals_hired != __SIZE_MAX__
		&& diner->philo.plates >= diner->meals_hired)
	{
		sem_close(diner->print);
		sem_close(diner->hashi);
		exit(EXIT_SUCCESS);
	}
}

void	act(t_data *diner, size_t duration)
{
	size_t	action_start;

	action_start = simulation_time(diner);
	while (simulation_time(diner) - action_start < duration)
	{
		usleep(10);
		what_am_i_feeling(diner);
	}
}
