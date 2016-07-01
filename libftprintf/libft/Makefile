# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quroulon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 17:00:10 by quroulon          #+#    #+#              #
#    Updated: 2016/04/19 13:08:35 by quroulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libft.a

CC			= 	gcc

CFLAGS		= 	-Wall -Werror -Wextra

SRC 		= 	$(wildcard *.c)

OBJ			=	$(SRC:.c=.o)
OBJ2		=	$(wildcard *gch)

HEADER 		= 	.

all: $(NAME)

.SILENT : $(NAME)
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -c -I $(HEADER) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

.SILENT : clean
clean:
	@rm -f $(OBJ) $(OBJ2)

.SILENT : fclean
fclean: clean
	@rm -f $(NAME)

re: fclean all
