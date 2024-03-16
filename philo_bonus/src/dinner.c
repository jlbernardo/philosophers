/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:49:46 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/15 22:41:36 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	dinner(t_data *diner)
{
	if (diner->seats == 1)
	{
		print_state(GRAB, diner);
		while (diner->open)
			what_am_i_feeling(diner);
	}
	if (diner->philo.id % 2 == 0)
		usleep(1000);
	while (diner->open)
	{
		eat(diner);
		nap(diner);
		think(diner);
	}
}

void	close_diner(t_data *diner)
{
	int		exit_status;
	size_t	full_guests;
	size_t	i;

	full_guests = 0;
	exit_status = EXIT_SUCCESS;
	while (!exit_status && full_guests < diner->seats)
	{
		waitpid(0, &exit_status, 0);
		full_guests++;
	}
	if (exit_status)
	{
		i = -1;
		while (++i < diner->seats)
			kill(diner->pid[i], SIGKILL);
	}
	free(diner->pid);
	sem_close(diner->hashi);
	sem_close(diner->print);
	sem_unlink("/hashi");
	sem_unlink("/print");
	usleep(100000);
	printf("└────────────────────────────────────┘\n");
}
