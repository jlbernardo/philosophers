/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:03:44 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/10 21:27:05 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	size_t			meals;
	size_t			guests;
	size_t			eat_time;
	size_t			die_time;
	size_t			sleep_time;
}				t_data;

typedef struct s_tab
{
	size_t			id;
	size_t			meals;
	size_t			last_meal;
	struct s_data	*data:
	pthread_t	philo;
	pthread_mutex_t	hashi;
}				t_tab;

typedef enum e_error
{
	ARGS = 0,
	NON_DIGIT
};

int		len(char *str);
int		wrong_arguments(int argc);
void	philerror(int args);
void	initializer(t_data *philo, int argc, char **argv);

#endif
