/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:05:18 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/11 13:42:14 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_data	philo;

	if (wrong_input(argc, argv))
		return (EXIT_FAILURE);
	initializer(&philo, argc, argv);
}
