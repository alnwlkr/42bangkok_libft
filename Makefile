# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panoma <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 02:56:01 by panoma            #+#    #+#              #
#    Updated: 2022/11/08 03:13:16 by panoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_isascii.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_tolower.c \
		ft_toupper.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%o: %c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
