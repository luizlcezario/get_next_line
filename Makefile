# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 13:53:47 by llima-ce          #+#    #+#              #
#    Updated: 2021/09/20 19:39:44 by llima-ce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./get_next_line
CC = gcc
SRCS = main.c get_next_line.c get_next_line_utils.c

CFLAGS = -D BUFFER_SIZE=1 

all: 
	${CC} ${CFLAGS} -g  ${SRCS} -o get_next_line

run:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-origins=yes --track-fds=yes ./get_next_line

clean:
	rm -f ${OBJS} 

fclean: clean
	rm -f ${NAME}

re: fclean all

git:
	git add .
	git commit -m changes
	git push

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
