# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 13:53:47 by llima-ce          #+#    #+#              #
#    Updated: 2021/09/22 16:55:59 by llima-ce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./get_next_line -fsanitize=address
CC = gcc
SRCS = main.c get_next_line_bonus.c get_next_line_utils_bonus.c

CFLAGS = -D BUFFER_SIZE=1 -Wall -Wextra -Werror

all: 
	${CC} ${CFLAGS} -g3  ${SRCS} -o get_next_line_bonus

run:
	valgrind --leak-check=full ./get_next_line_bonus

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
