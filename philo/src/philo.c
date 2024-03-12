/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:05:18 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/11 16:33:37 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	diner;

	if (reservation_mistake(argc, argv))
		return (EXIT_FAILURE);
	register_guests(&diner, argc, argv);
	serve_tables(&diner);
	close_diner(&diner);
	return (EXIT_SUCCESS);
}
