/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:19:22 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/15 16:45:13 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>

/* types of errors */
# define ARGS		0
# define NON_DIGIT	1
# define NEGATIVE	2

/* error messages */
# define NOT_NBR	0
# define TOO_FEW	1
# define TOO_MANY	2

/* philo states */
# define EAT		0
# define SLEEP		1
# define THINK		2
# define GRAB		3
# define DEAD		4

/* door flags */
# define CHECK		0
# define CLOSE		1

typedef struct s_tab
{
	char			*sem_name;
	size_t			id;
	size_t			plates;
	size_t			last_meal;
	pthread_t		owner;
}				t_tab;

typedef struct s_data
{
	bool			open;
	sem_t			*close;
	sem_t			*print;
	sem_t			*hashi;
	sem_t			*check;
	size_t			sleep_time;
	size_t			meals_hired;
	size_t			eat_time;
	size_t			die_time;
	size_t			start;
	size_t			seats;
	struct s_tab	philo;
}				t_data;

void	print_header(void);
void	dinner(t_data *diner);
void	close_diner(t_data *diner);
void	serve_tables(t_data *diner);
void	register_guests(t_data *diner, int argc, char **argv);

void	message(int flag);
bool	non_digits(char **argv);
void	philerror(int args, int flag);
bool	reservation_mistake(int argc, char **argv);

size_t	print_state(int state, t_data *diner);

void	eat(t_data *diner);
void	nap(t_data *diner);
void	think(t_data *diner);
void	what_am_i_feeling(t_data *diner);

void	*owner(void *data);

int		num_len(size_t nbr);
size_t	atost(char *str);
size_t	len(const char *str);
size_t	simulation_time(t_data *diner);
bool	diner_door(t_data *diner, int flag);
char	*semaphore_name(size_t philo_id);

#endif
