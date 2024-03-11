/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:31:24 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/10 16:51:57 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philerror(int args)
{
	char	*less;
	char	*more;

	less = "I think you forgot to provide some arguments.\nRemember to input "
		"the amount of philosophers and how long they take to die, to eat and "
		"to sleep. In this order, specifically.\nYou can also specify how many "
		"meals they should eat in total";
	more = "Seems like you gave me too many arguments.\n You should only "
		"provide number of philo and times to die, eat and sleep. Number of "
		"meals too, if you prefer. Try again?";
	if (args < 5)
		write(STDERR_FILENO, less, len(less));
	else if (args > 6)
		write(STDERR_FILENO, more, len(more));
}

int	len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
