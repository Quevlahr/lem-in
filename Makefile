# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/28 20:38:08 by quroulon          #+#    #+#              #
#    Updated: 2016/09/28 16:29:46 by quroulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lem-in

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

SRC			=	$(wildcard *.c)

OBJ			=	$(SRC:.c=.o) 

LIB			=	-Llibft libft/libft.a

HEADER		=	lem-in.h libft/libft.h

all: $(NAME)

$(NAME): $(OBJ)
	@make -sC libft/
	@$(CC) $(CFLAGS) -c -I $(HEADER) $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo "COMPILATION DONE"

clean:
	@make clean -sC libft/
	@rm -f $(OBJ)
	@echo "CLEAN DONE"

fclean: clean
	@make fclean -sC libft/
	@rm -f $(NAME)
	@echo "FCLEAN DONE"

re: fclean all
