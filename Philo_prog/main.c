/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mounali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:55:30 by mounali           #+#    #+#             */
/*   Updated: 2023/09/05 23:09:36 by mounali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_p(t_all *all)
{
	int	i;

	i = 0;
	all->ti_start = timer();
	if (all->ti_start == 1)
		return (1);
	pthread_mutex_init(&all->m_end, NULL);
	pthread_mutex_init(&all->m_dead, NULL);
	while (i < all->nbr_p)
	{
		all->ph[i].all = all;
		all->ph[i].id = i + 1;
		all->ph[i].ate = 0;
		all->ph[i].last_ate = timer();
		pthread_mutex_init(&all->ph[i].left, NULL);
		if (i < all->nbr_p - 1)
			all->ph[i].right = &all->ph[i + 1].left;
		else
			all->ph[i].right = &all->ph[0].left;
		i++;
	}
	return (0);
}

int	create_thread(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nbr_p)
	{
		if (pthread_create(&all->ph[i].thr_id, NULL, \
				thread_routine, &all->ph[i]) != 0)
			return (ft_exit("Error\nCreate thread failed\n"));
		i++;
	}
	return (0);
}

void	cleaning(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nbr_p)
		pthread_join(all->ph[i++].thr_id, NULL);
	free(all->ph);
}

int	main(int ac, char **av)
{
	t_all	all;

	if (check_gived_arg(ac, av, &all))
		return (1);
	if (all.nbr_p == 1)
	{
		printf("0 Philo 1 has taken a fork\n");
		printf("%d Philo 1 died \n", all.time_if_no_eat_die);
		free(all.ph);
		return (0);
	}
	if (create_p(&all) || create_thread(&all))
	{
		free(all.ph);
		return (1);
	}
	cleaning(&all);
	return (0);
}
