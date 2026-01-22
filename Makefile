# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/05 13:01:41 by jemonthi          #+#    #+#              #
#    Updated: 2025/12/05 13:04:23 by jemonthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

CC	=		cc

CFLAGS	=	-Wall -Wextra -Werror

SOURCES	=	sources/error_and_free.c \
		 	sources/ft_split.c \
		 	sources/ft_strjoin.c \
			sources/pipex.c \
			sources/utility_functions.c 

OBJECTS =	$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean re
