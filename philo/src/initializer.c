/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:53:48 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/10 20:38:37 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	atost(char *str);

void	initializer(t_data *philo, int argc, char **argv)
{
	philo->guests = atost(*argv[1]);
	philo->die_time = atost(*argv[2]);
	philo->eat_time = atost(*argv[3]);
	philo->sleep_time = atost(*argv[4]);
	if (argc == 6)
		philo->meals = atost(*argv[5]);
	else
		philo->meals = __SIZE_MAX__;
	init_threads(philo);
	init_mutexes(philo);
}

void	init_threads(t_data *philo)
{
	int	i;

	i = 0;
	philo->thinker = malloc(philo->guests * sizeof(pthread_t));
	while (i < philo->guests)
	{
		pthread_create(philo->thinker[i], NULL, NULL, NULL);
		i++;
	}
}

void	init_mutexes(t_data *philo)
{
	int	i;

	i = 0;
	philo->hashi = malloc(philo->guests * sizeof(pthread_mutex_t));
	while (i < philo->guests)
	{
		pthread_mutex_init(&philo->hashi[i], NULL);
		i++;
	}
}

size_t	atost(char *str)
{
	size_t	i;
	size_t	num;
	size_t	negative;

	i = 0;
	num = 0;
	negative = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative++;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (negative == 1)
		num = -num;
	return (num);
}
