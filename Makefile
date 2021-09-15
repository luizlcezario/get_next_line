# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 13:53:47 by llima-ce          #+#    #+#              #
#    Updated: 2021/09/15 13:36:57 by llima-ce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out
CC = gcc
SRCS = main.c get_next_line.c get_next_line_utils.c

CFLAGS = -I . -Wall -Wextra -Werror -D BUFFER_SIZE=10000

all: $(NAME)
	${CC} ${CFLAGS} ${SRCS} 
	
	
clean:
	rm -f ${OBJS} 

fclean: clean
	rm -f ${NAME}

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
