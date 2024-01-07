# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mounali <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 21:49:56 by mounali           #+#    #+#              #
#    Updated: 2023/09/05 22:03:05 by mounali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = algo.c check_arg.c func.c\
       main.c

HDRS = philo.h

OBJS = $(SRCS:.c=.o)

NAME = philo

CC =   gcc

CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm -f

all:  $(NAME)


$(MOBJS):$(HDRS) Makefile
$(OBJS):$(HDRS) Makefile

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all


