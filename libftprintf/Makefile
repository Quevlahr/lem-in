# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/31 15:34:11 by quroulon          #+#    #+#              #
#    Updated: 2016/07/01 15:56:53 by quroulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libftprintf.a

CC			= 	gcc

CFLAGS		= 	-Wall -Werror -Wextra

SRC			=	flags.c flags_application.c flags_application2.c ft_forstr.c ft_gestion.c \
				ft_init.c ft_printf.c ft_space.c ft_space_int.c ft_space_str.c va_list.c \
				va_list2.c va_list_octal.c va_list_str.c

SRCPRINTF	=	libft_ull/ft_itoabase_uc.c libft_ull/ft_itoabase_ui.c libft_ull/ft_itoabase_ull.c \
				libft_ull/ft_itoabase_us.c libft_ull/ft_nbrlen_l.c libft_ull/ft_nbrlen_ll.c \
				libft_ull/ft_nbrlen_ui.c libft_ull/ft_nbrlen_ul.c libft_ull/ft_nbrlen_ull.c \
				libft_ull/ft_putnbr_l.c libft_ull/ft_putnbr_ll.c libft_ull/ft_putnbr_ui.c \
				libft_ull/ft_putnbr_ul.c libft_ull/ft_putnbr_ull.c libft_ull/ft_wstrlen.c

SRCLIBFT	=	libft/ft_abs.c libft/ft_atoi.c libft/ft_atoi_ll.c libft/ft_atoibase.c libft/ft_bzero.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_ishexa.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_itoabase.c libft/ft_linelen.c libft/ft_lstadd.c libft/ft_lstat.c libft/ft_lstclear.c libft/ft_lstcontentsize.c libft/ft_lstdel.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstlen.c libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_lstprint.c libft/ft_lstpush.c libft/ft_lstrev.c libft/ft_lstsize.c libft/ft_lsttochar.c libft/ft_memalloc.c libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memdel.c libft/ft_memmove.c libft/ft_memset.c libft/ft_nbrlen.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putendl.c libft/ft_putendl_fd.c libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putnbrdl.c libft/ft_putstr.c libft/ft_putstr_fd.c libft/ft_strcat.c libft/ft_strchr.c libft/ft_strclr.c libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdel.c libft/ft_strdup.c libft/ft_strequ.c libft/ft_striter.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlen.c libft/ft_strmap.c libft/ft_strmapi.c libft/ft_strncat.c libft/ft_strncmp.c libft/ft_strncpy.c libft/ft_strnequ.c libft/ft_strnew.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strsplit.c libft/ft_strstr.c libft/ft_strsub.c libft/ft_strtrim.c libft/ft_tolower.c libft/ft_toupper.c libft/get_next_line.c

OBJ			=	$(SRC:.c=.o) $(notdir $(SRCPRINTF:.c=.o)) $(notdir $(SRCLIBFT:.c=.o))

HEADER 		=	ft_printf.h libft/libft.h


all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	@$(CC) $(CFLAGS) -c -I $(HEADER) $(SRC) $(SRCPRINTF) $(SRCLIBFT)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

.SILENT : clean
clean:
	@rm -f $(OBJ)

.SILENT : fclean
fclean: clean
	@rm -f $(NAME)

re: fclean all
