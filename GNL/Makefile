# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prafal- <prafaegcost-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 13:53:47 by llima-ce          #+#    #+#              #
#    Updated: 2021/09/22 21:52:465 by prafae-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./get_next_line 
CC = gcc

SRCS = main.c get_next_line.c get_next_line_utils.c

CFLAGS = -D BUFFER_SIZE=1 

all: $(NAME)
	${CC} ${CFLAGS} -g  ${SRCS} -o get_next_line
	
.PHONY: all 