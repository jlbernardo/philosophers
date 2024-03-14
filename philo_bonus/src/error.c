/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:36:12 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/13 23:36:44 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	reservation_mistake(int argc, char **argv)
{
	if (non_digits(argv))
		philerror(argc, NON_DIGIT);
	else if (argc > 6 || argc < 5)
		philerror(argc, ARGS);
	else
		return (false);
	return (true);
}

void	philerror(int args, int flag)
{
	if (flag == ARGS && args < 5)
		message(TOO_FEW);
	if (flag == ARGS && args > 6)
		message(TOO_MANY);
	if (flag == NON_DIGIT)
		message(NOT_NBR);
}

void	message(int flag)
{
	const char	*msg[3] = {
		"Use only numbers!\n\033[0m No sign, no letters... Just numbers.",
		"Too few arguments.\033[0m",
		"Too many arguments, bud!\033[0m",
	};
	const char	*guide
		= "\n Remember the order: [🧐] [⏳💀] [⏳🍜] [⏳💤] [🍽️  (optional)]\n\n";

	write(STDERR_FILENO, "\n \033[1;31m", 12);
	write(STDERR_FILENO, msg[flag], len(msg[flag]));
	write(STDERR_FILENO, guide, len(guide));
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
