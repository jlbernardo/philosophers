/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:53:48 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/11 14:50:40 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initializer(t_data *philo, int argc, char **argv)
{
	philo->guests = atost(argv[1]);
	philo->die_time = atost(argv[2]);
	philo->eat_time = atost(argv[3]);
	philo->sleep_time = atost(argv[4]);
	if (argc == 6)
		philo->meals = atost(argv[5]);
	else
		philo->meals = __SIZE_MAX__;
	philo->thinker = malloc(philo->guests * sizeof(t_tab));
	init_guests_tab(philo);
}

void	*test_routine(void *test)
{
	return (test);
}

void	init_guests_tab(t_data *philo)
{
	size_t	i;

	i = 0;
	while (i < philo->guests)
	{
		pthread_create(&philo->thinker[i].philo, NULL, &test_routine, NULL);
		pthread_mutex_init(&philo->thinker[i].hashi, NULL);
		philo->thinker[i].data = philo;
		philo->thinker[i].id = i;
		philo->thinker[i].meals = 0;
		i++;
	}
}
