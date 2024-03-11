/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:43:08 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/11 14:50:31 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wrong_input(int argc, char **argv)
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
