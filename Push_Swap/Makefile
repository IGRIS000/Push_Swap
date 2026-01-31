# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichtioui <ichtioui@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/23 11:32:07 by ichtioui          #+#    #+#              #
#    Updated: 2026/01/03 11:59:35 by ichtioui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = error_handle.c stack_utils.c stack_parse.c \
		ft_push.c ft_swap.c ft_rotate.c ft_rev_rot.c \
		sort.c sort_helper.c
SRCSM = push_swap.c
SRCSB = checker_bonus.c gnl/get_next_line.c gnl/get_next_line_utils.c
NAME = push_swap
NAMEB = checker
OBJS = $(SRCS:.c=.o)
OBJSM = $(SRCSM:.c=.o)
OBJSB = $(SRCSB:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(OBJSM)
	$(CC) $(CFLAGS) $(OBJS) $(OBJSM) -o $@

bonus: all $(NAMEB)

$(NAMEB): $(OBJS) $(OBJSB)
	$(CC) $(CFLAGS) $(OBJS) $(OBJSB) -o $@

clean:
	$(RM) $(OBJS) $(OBJSM) $(OBJSB)

fclean: clean
	$(RM) $(NAME) $(NAMEB)

re: fclean all

.PHONY: all fclean clean bonus re