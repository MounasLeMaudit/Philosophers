/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mounali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:45:26 by mounali           #+#    #+#             */
/*   Updated: 2023/09/05 21:46:15 by mounali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_p
{
	int				id;
	int				ate;
	long int		last_ate;
	struct s_all	*all;
	pthread_t		thr_id;
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
}	t_p;

typedef struct s_all
{
	int				nbr_p;
	int				time_if_no_eat_die;
	int				timefor_eat;
	int				timefor_sleep;
	int				nbr_must_eat;
	int				dead;
	int				end;
	long int		ti_start;
	t_p				*ph;
	pthread_mutex_t	m_end;
	pthread_mutex_t	m_dead;
}	t_all;

int			ft_exit(char *s);
int			check_gived_arg(int ac, char **av, t_all *all);
int			ft_atoi(char *str);
long int	timer(void);
void		print_status(char *s, t_p *ph);
void		*thread_routine(void *data);

#endif
