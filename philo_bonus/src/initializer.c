/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juliany Bernardo <julberna@student.42sp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:46:37 by Juliany Ber       #+#    #+#             */
/*   Updated: 2024/03/14 01:25:19 by Juliany Ber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	register_guests(t_data *diner, int argc, char **argv)
{
	if (argc == 6)
		diner->meals_hired = atost(argv[5]);
	else
		diner->meals_hired = __SIZE_MAX__;
	diner->open = true;
	diner->seats = atost(argv[1]);
	diner->die_time = atost(argv[2]);
	diner->eat_time = atost(argv[3]);
	diner->sleep_time = atost(argv[4]);
	diner->print = sem_open("print", O_CREAT, O_RDWR, 1);
	diner->close = sem_open("close", O_CREAT, O_RDWR, 1);
	diner->hashi = sem_open("hashi", O_CREAT, O_RDWR, diner->seats);
	diner->philo = malloc(1 * sizeof(t_tab));
}

void	serve_tables(t_data *diner)
{
	size_t			i;
	size_t			pid;
	struct timeval	time;

	i = -1;
	print_header();
	gettimeofday(&time, NULL);
	diner->start = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	while (++i < diner->seats)
	{
		pid = fork();
		if (pid == 0)
		{
			diner->philo->id = i;
			diner->philo->plates = 0;
			diner->philo->last_meal = 0;
			diner->philo->sem_name = semaphore_name(i);
			diner->check = sem_open(diner->philo->sem_name, O_CREAT, O_RDWR, 1);
			pthread_create(&diner->philo->owner, NULL, &owner, (void *)diner);
			pthread_detach(diner->philo->owner);
			dinner(diner);
		}
	}
}

char	*semaphore_name(size_t philo_id)
{
	int		size;
	char	*name;

	size = num_len(philo_id) + 1;
	name = malloc(size * sizeof(char));
	if (!name)
		return (NULL);
	name[--size] = '\0';
	while (size > 0)
	{
		size--;
		name[size] = philo_id % 10 + '0';
		philo_id /= 10;
	}
	return (name);
}

void	print_header(void)
{
	printf("┌────────────────────────────────────┐\n");
	printf("│ TIME    ID           ACTION        │\n");
	printf("├────────────────────────────────────┤\n");
}
