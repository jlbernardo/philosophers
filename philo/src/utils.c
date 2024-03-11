/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:47:02 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/11 14:50:36 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
