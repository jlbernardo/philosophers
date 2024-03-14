/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:35:16 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/13 20:45:55 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
