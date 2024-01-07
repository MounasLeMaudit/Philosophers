/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mounali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:07:21 by mounali           #+#    #+#             */
/*   Updated: 2023/09/05 22:45:26 by mounali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_exit(char *s)
{
	printf("%s", s);
	return (1);
}

int	check_arg(int ac, char **av)
{
	int			i;
	int			m;
	long int	r;

	m = 1;
	while (m < ac)
	{
		i = 0;
		r = 0;
		if (av[m][0] == '-')
			return (ft_exit("Error\nNegative number\n"));
		if (av[m][0] == '+')
			i++;
		while (av[m][i])
		{
			if (av[m][i] < '0' || av[m][i] > '9')
				return (ft_exit("Error\nNot number\n"));
			r = r * 10 + av[m][i++] - 0;
			if (r > 2147483647)
				return (ft_exit("Error\nNot int\n"));
		}
		m++;
	}
	return (0);
}

int	check_gived_arg(int ac, char **av, t_all *all)
{
	if (ac < 5)
		return (ft_exit("Error\nNot enough args\n"));
	else if (ac > 6)
		return (ft_exit("Error\nToo much args\n"));
	if (check_arg(ac, av))
		return (1);
	if (ft_atoi(av[1]) == 0)
		return (ft_exit("Error\nAt least 1 philosopher\n"));
	all->end = 0;
	all->nbr_p = ft_atoi(av[1]);
	all->time_if_no_eat_die = ft_atoi(av[2]);
	all->timefor_eat = ft_atoi(av[3]);
	all->timefor_sleep = ft_atoi(av[4]);
	all->dead = 0;
	if (ac == 5)
		all->nbr_must_eat = -1;
	else
		all->nbr_must_eat = ft_atoi(av[5]);
	all->ph = malloc(sizeof(t_p) * all->nbr_p);
	if (!all->ph)
		return (ft_exit("Error\nMalloc\n"));
	return (0);
}
