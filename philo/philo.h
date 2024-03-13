/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:03:44 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/12 23:54:37 by Juliany Ber      ###   ########.fr       */
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
# define DEAD		4

/* loooooooooop */
# define RESTAURAND_IS_OPEN_AND_SERVING	42

typedef enum e_mutex
{
	OPEN = 0,
	START,
	SEATS,
	MEALS,
	TIME_TO_EAT,
	TIME_TO_DIE,
	TIME_TO_SLEEP,
	PHILO_ID,
	PHILO_PLATES,
	PHILO_LAST_MEAL,
	TOTAL_MUTEXES
}			t_mutex;

typedef struct s_data
{
	bool			open;
	size_t			start;
	size_t			seats;
	size_t			eat_time;
	size_t			die_time;
	size_t			meals_hired;
	size_t			sleep_time;
	pthread_t		waiter;
	struct s_tab	*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	peek[TOTAL_MUTEXES];
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

/* dinner */
void	*dinner(void *tab);
void	close_diner(t_data *diner);

/* philo actions */
void	eat(t_tab *philo);
void	nap(t_tab *philo);
void	think(t_tab *philo);
void	grab_hashis(t_tab *philo);
void	drop_hashis(t_tab *philo);

/* checker */
bool	non_digits(char **argv);
void	*restaurant_open(void *data);
bool	nobody_died(t_data *diner, size_t seats);
bool	reservation_mistake(int argc, char **argv);
size_t	check_whos_full(t_data *diner, size_t meals, size_t seats);

/* mutexes */
size_t	philo_id(t_tab *philo);
size_t	seats_taken(t_data *diner);
size_t	time_to_eat(t_data *diner);
size_t	time_to_die(t_data *diner);
size_t	meals_hired(t_data *diner);
size_t	philo_plates(t_tab *philo);
size_t	time_to_sleep(t_data *diner);
size_t	philo_last_meal(t_tab *philo);
size_t	simulation_time(t_data *diner);
size_t	print_state(int state, t_tab *philo);
bool	diner_open(t_data *diner);

/* error */
void	message(int flag);
void	philerror(int args, int flag);

/* auxiliary functions */
size_t	len(const char *str);
size_t	atost(char *str);

#endif
