/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:47:02 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/11 21:05:06 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(int state, t_tab *philo)
{
	const char	*message[4] = {
		"is eating",
		"is sleeping",
		"is thinking",
		"has taken a hashi",
	};

	pthread_mutex_lock(&philo->diner->print);
	printf("%zu %s\n", philo->id, message[state]);
	pthread_mutex_unlock(&philo->diner->print);
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

int	len(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
