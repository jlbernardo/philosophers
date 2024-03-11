/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:03:44 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/11 13:35:03 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

/* types of errors */
# define ARGS		0
# define NON_DIGIT	1
# define NEGATIVE	2

/* error messages */
# define TOO_FEW	0
# define TOO_MANY	1
# define NOT_NBR	2

typedef struct s_data
{
	size_t			meals;
	size_t			guests;
	size_t			eat_time;
	size_t			die_time;
	size_t			sleep_time;
	struct s_tab	*thinker;
}				t_data;

typedef struct s_tab
{
	size_t			id;
	size_t			meals;
	size_t			last_meal;
	t_data			*data;
	pthread_t		philo;
	pthread_mutex_t	hashi;
}				t_tab;

/* set up */
void	init_guests_tab(t_data *philo);
void	initializer(t_data *philo, int argc, char **argv);

/* checker */
int		non_digits(char **argv);
int		wrong_input(int argc, char **argv);

/* error */
void	message(int flag);
void	philerror(int args, int flag);

/* auxiliary functions */
int		len(const char *str);
size_t	atost(char *str);

#endif
