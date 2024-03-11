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

void	philerror(int args, int flag)
{
	if (flag == ARGS && args < 5)
		message(0);
	if (flag == args && args > 6)
		message(1);
	if (flag == NON_DIGIT)
		message(2);
}

void	message(int flag)
{
	static const char	*msg[2] = {
		"I think you forgot to provide some arguments.\n"
		"Remember to input the amount of philosophers and how long "
		"they take to die, to eat and to sleep. In this order, "
		"specifically.\nYou can also specify how many "
                "meals they should eat in total.\n",
		"Seems like you gave me too many arguments.\n You should only "
                "provide number of philo and times to die, eat and sleep. "
		"Number of meals too, if you prefer. Try again?\n",
		"Only numbers are allowed. You can use signed numbers, sure, "
		"but negative ones will also gonna give you an error.\n",
		"Have you ever seen negative time or negative people?\n"
		"Yeah, don't think so. Try being reasonable next run.\n",
	}
	
	write(STDERR_FILENO, msg[flag], len(msg[flag]);
}

int	len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
