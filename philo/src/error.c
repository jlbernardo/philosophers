/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:31:24 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/12 23:42:51 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		"I think you forgot to provide some arguments.\n"
		"Please, provide the amount of philosophers and how long "
		"they take to die, to eat and to sleep.\nIn this order, "
		"specifically. You can also specify how many "
		"meals they should eat in total.\n",
		"Only numbers are allowed as arguments.\nThere's no reason to use "
		"positive or negative signs as time is only positive, right? :D\n",
		"Seems like you gave me too many arguments.\nYou should only "
		"provide number of philo and times to die, eat and sleep. "
		"Number of meals too, if you prefer. Try again?\n",
	};

	write(STDERR_FILENO, msg[flag], len(msg[flag]));
}
