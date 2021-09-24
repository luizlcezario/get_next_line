# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 13:53:47 by llima-ce          #+#    #+#              #
#    Updated: 2021/09/23 16:56:54 by llima-ce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRCS = example_main.c get_next_line.c get_next_line_utils.c

CFLAGS = -D BUFFER_SIZE=1 

all: $(NAME)
	${CC} ${CFLAGS} -g  ${SRCS} -o get_next_line
	
git: 
	git add .
	git commit -m "auto git"
	git push 

.PHONY: all git
