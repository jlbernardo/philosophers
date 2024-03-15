/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:49:46 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/15 16:46:34 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	dinner(t_data *diner)
{
	if (diner->seats == 1)
	{
		print_state(GRAB, diner);
		while (diner_door(diner, CHECK))
			what_am_i_feeling(diner);
	}
	while (diner_door(diner, CHECK))
	{
		eat(diner);
		nap(diner);
		think(diner);
	}
	sem_close(diner->check);
	sem_unlink(diner->philo.sem_name);
	free(diner->philo.sem_name);
	exit(EXIT_SUCCESS);
}

void	close_diner(t_data *diner)
{
	while (waitpid(-1, NULL, 0) > 0)
		;
	sem_close(diner->hashi);
	sem_close(diner->print);
	sem_close(diner->close);
	sem_unlink("/hashi");
	sem_unlink("/print");
	sem_unlink("/close");
	printf("└────────────────────────────────────┘\n");
}
