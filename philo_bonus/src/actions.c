/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:08:33 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/14 00:41:11 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_data *diner)
{
	sem_wait(diner->hashi);
	sem_wait(diner->hashi);
	if (diner_door(diner, CHECK))
		return ;
	diner->philo->last_meal = print_state(EAT, diner);
	usleep(diner->eat_time * 1000);
	diner->philo->plates++;
	sem_post(diner->hashi);
	sem_post(diner->hashi);
	what_am_i_feeling(diner);
}

void	nap(t_data *diner)
{
	if (diner_door(diner, CHECK))
		return ;
	print_state(SLEEP, diner);
	usleep(diner->sleep_time * 1000);
	what_am_i_feeling(diner);
}

void	think(t_data *diner)
{
	if (diner_door(diner, CHECK))
		return ;
	print_state(THINK, diner);
	usleep(1000);
	what_am_i_feeling(diner);
}

void	what_am_i_feeling(t_data *diner)
{
	if (simulation_time(diner) - diner->start >= diner->die_time)
	{
		print_state(DEAD, diner);
		sem_post(diner->close);
		diner_door(diner, CLOSE);
	}
	if (diner->meals_hired != __SIZE_MAX__
		&& diner->philo->plates >= diner->meals_hired)
		diner_door(diner, CLOSE);
}
