/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:43:08 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/11 21:07:11 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	reservation_mistake(int argc, char **argv)
{
	if (non_digits(argv))
		philerror(argc, NON_DIGIT);
	else if (argc > 6 || argc < 5)
		philerror(argc, ARGS);
	else
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	non_digits(char **argv)
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

int	restaurant_open(t_data *diner)
{
	size_t	i;
	bool	open;

	open = false;
	i = 0;
	while (i < diner->seats)
	{
		if (diner->philo[i].plates < diner->meals_hired
			|| diner->meals_hired == __SIZE_MAX__)
		{
			open = true;
			break ;
		}
		i++;
	}
	return (open);
}
