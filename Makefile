# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molabhai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 10:06:25 by molabhai          #+#    #+#              #
#    Updated: 2021/06/17 10:06:26 by molabhai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

FLAGS= -Wall -Wextra -Werror

CC= gcc -g

SRCS= push_swap.c push_swap_instruction.c push_algo.c push_algo_helper.c \
		push_algo_helper_two.c push_algo_helper_three.c push_algo_helper_four.c \
		push_algo_helper_five.c


OBJ= $(SRCS:.c=.o)

MAKINGLIBFT= cd Libft && make -f Makefile

all: $(NAME)
$(NAME):
		$(MAKINGLIBFT)
		$(CC) $(FLAGS) $(SRCS) Libft/libft.a -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all