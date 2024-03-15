/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   owner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:16:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/15 16:45:44 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*owner(void *data)
{
	t_data	*diner;

	diner = (t_data *)data;
	sem_wait(diner->close);
	sem_post(diner->close);
	diner_door(diner, CLOSE);
	return (data);
}

bool	diner_door(t_data *diner, int flag)
{
	bool	open;

	open = true;
	sem_wait(diner->check);
	if (flag == CLOSE)
		diner->open = false;
	open = diner->open;
	sem_post(diner->check);
	return (open);
}
