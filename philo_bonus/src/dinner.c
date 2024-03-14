/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:49:46 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/14 01:08:41 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	dinner(t_data *diner)
{
	while (diner_door(diner, CHECK))
	{
		eat(diner);
		nap(diner);
		think(diner);
	}
	free(diner->philo->sem_name);
	free(diner->philo);
	sem_close(diner->check);
	exit(EXIT_SUCCESS);
}

void	close_diner(t_data *diner)
{
	while (waitpid(-1, NULL, 0) > 0)
		;
	free(diner->philo);
	sem_close(diner->hashi);
	sem_close(diner->print);
	sem_close(diner->close);
	printf("└────────────────────────────────────┘\n");
}
