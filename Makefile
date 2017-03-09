# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 17:06:20 by eurodrig          #+#    #+#              #
#    Updated: 2017/02/08 00:56:19 by eurodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS  = ./src/ft_printf.c \
				./src/ft_printf_params_init.c \
				./src/ft_printf_flags.c \
				./src/ft_printf_length.c \
				./src/ft_printf_width.c \
				./src/ft_printf_precision.c \
				./src/ft_printf_s.c \
				./src/ft_max_number.c \
				./src/ft_print_blank.c \
				./src/ft_printf_str_trim.c \
				./src/ft_putchar_n_bytes.c \
				./src/ft_str_contains.c \
				./src/ft_wstrlen.c \

OBJS =	ft_printf.o \
				ft_printf_params_init.o \
				ft_printf_flags.o \
				ft_printf_length.o \
				ft_printf_width.o \
				ft_printf_precision.o \
				ft_printf_s.o \
				ft_max_number.o \
				ft_print_blank.o \
				ft_printf_str_trim.o \
				ft_putchar_n_bytes.o \
				ft_str_contains.o \
				ft_wstrlen.o \


all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRCS) -I includes/libft/
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
