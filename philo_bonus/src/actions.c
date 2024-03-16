/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:08:33 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/15 23:29:44 by Juliany Ber      ###   ########.fr       */
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
	usleep(diner->eat_time * 1000);
	diner->philo.plates++;
	sem_post(diner->hashi);
	sem_post(diner->hashi);
}

void	nap(t_data *diner)
{
	print_state(SLEEP, diner);
	dream(diner);
	what_am_i_feeling(diner);
}

void	think(t_data *diner)
{
	print_state(THINK, diner);
	usleep(1000);
	what_am_i_feeling(diner);
}

void	what_am_i_feeling(t_data *diner)
{
	if (simulation_time(diner) - diner->philo.last_meal >= diner->die_time)
	{
		sem_wait(diner->print);
		printf("│ %zu%*s%zu%*s%-22s │\n", simulation_time(diner),
			8 - num_len(simulation_time(diner)), " ", diner->philo.id,
			6 - num_len(diner->philo.id), " ", "💀 died");
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

void	dream(t_data *diner)
{
	size_t	i;

	i = 0;
	while (i < diner->sleep_time)
	{
		usleep(2000);
		what_am_i_feeling(diner);
		i += 2;
	}
}
