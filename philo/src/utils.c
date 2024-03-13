/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:47:02 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/12 23:06:53 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	print_state(int state, t_tab *philo)
{
	size_t		current_time;
	const char	*message[5] = {
		"is eating",
		"is sleeping",
		"is thinking",
		"has taken a hashi",
		"died",
	};

	if (!diner_open(philo->diner))
		return (0);
	current_time = simulation_time(philo->diner);
	pthread_mutex_lock(&philo->diner->print);
	printf("%zu %zu %s\n", current_time, philo->id, message[state]);
	pthread_mutex_unlock(&philo->diner->print);
	return (current_time);
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
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (negative == 1)
		num = -num;
	return (num);
}

size_t	len(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

bool	non_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9'))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
