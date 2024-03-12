/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:03:44 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/11 21:05:30 by Juliany Ber      ###   ########.fr       */
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

/* philo states */
# define EAT		0
# define SLEEP		1
# define THINK		2
# define GRAB		3

typedef struct s_data
{
	size_t			seats;
	size_t			eat_time;
	size_t			die_time;
	size_t			meals_hired;
	size_t			sleep_time;
	pthread_t		waiter;
	struct s_tab	*philo;
	pthread_mutex_t	print;
}				t_data;

typedef struct s_tab
{
	size_t			id;
	size_t			plates;
	size_t			last_meal;
	t_data			*diner;
	pthread_t		guest;
	pthread_mutex_t	hashi;
}				t_tab;

/* set up */
void	serve_tables(t_data *diner);
void	register_guests(t_data *diner, int argc, char **argv);

/* checker */
int		non_digits(char **argv);
int		restaurant_open(t_data *diner);
int		reservation_mistake(int argc, char **argv);

/* dinner */
void	*dinner(void *tab);
void	close_diner(t_data *diner);

/* philo actions */
void	eat(t_tab *philo);
void	nap(t_tab *philo);
void	think(t_tab *philo);
void	grab_hashis(t_tab *philo);
void	drop_hashis(t_tab *philo);

/* error */
void	message(int flag);
void	philerror(int args, int flag);

/* auxiliary functions */
size_t	atost(char *str);
int		len(const char *str);
void	print_state(char *state, t_tab *philo);

#endif
