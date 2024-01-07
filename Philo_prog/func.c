/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mounali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:58:48 by mounali           #+#    #+#             */
/*   Updated: 2023/09/05 23:25:35 by mounali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + *str - 48;
		str++;
	}
	return (res * sign);
}

long int	timer(void)
{
	long int		r;
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (ft_exit("Error\nGettimeofday failed\n"));
	r = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (r);
}

void	print_status(char *s, t_p *ph)
{
	long int	time;
	int			i;

	i = 31 + (ph->id % 7);
	pthread_mutex_lock(&ph->all->m_end);
	pthread_mutex_lock(&ph->all->m_dead);
	time = timer() - ph->all->ti_start;
	if (ph->all->end != ph->all->nbr_p && !ph->all->dead)
	{
		if (! (ph->all->time_if_no_eat_die / 2 <= ph->all->timefor_eat
				&& time > ph->all->time_if_no_eat_die))
		{
			printf("\033[%dm""%ld Philo %d ", i, time, ph->id);
			printf("%s (ate %d times)\n""\033[00m", s, ph->ate);
		}
	}
	pthread_mutex_unlock(&ph->all->m_dead);
	pthread_mutex_unlock(&ph->all->m_end);
}
