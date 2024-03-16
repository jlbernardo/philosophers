/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:37:38 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/15 22:17:14 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	print_state(int state, t_data *diner)
{
	char		*s;
	size_t		current_time;
	const char	*message[5] = {
		"🤤 is eating",
		"😪 is sleeping",
		"🧐 is thinking",
		"🥢 has taken a hashi",
		"💀 died",
	};

	s = " ";
	current_time = simulation_time(diner);
	sem_wait(diner->print);
	printf("│ %zu%*s%zu%*s%-22s │\n", current_time, 8 - num_len(current_time),
		s, diner->philo.id, 6 - num_len(diner->philo.id), s, message[state]);
	if (state != DEAD)
		sem_post(diner->print);
	return (current_time);
}

size_t	simulation_time(t_data *diner)
{
	size_t			simulation;
	struct timeval	time;

	gettimeofday(&time, NULL);
	simulation = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	simulation -= diner->start;
	return (simulation);
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

int	num_len(size_t nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}
