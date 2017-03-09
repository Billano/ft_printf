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

CFLAG = -c -Wall -Werror -Wextra

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

LIB_OBJS = includes/libft/ft_memset.o \
			includes/libft/ft_bzero.o \
			includes/libft/ft_memcpy.o \
			includes/libft/ft_memccpy.o \
			includes/libft/ft_memmove.o \
			includes/libft/ft_memchr.o \
			includes/libft/ft_memcmp.o \
			includes/libft/ft_strlen.o \
			includes/libft/ft_strdup.o \
			includes/libft/ft_strcpy.o \
			includes/libft/ft_strncpy.o \
			includes/libft/ft_strcat.o \
			includes/libft/ft_strncat.o \
			includes/libft/ft_strlcat.o \
			includes/libft/ft_strchr.o \
			includes/libft/ft_strrchr.o \
			includes/libft/ft_strstr.o \
			includes/libft/ft_strnstr.o \
			includes/libft/ft_strcmp.o \
			includes/libft/ft_strncmp.o \
			includes/libft/ft_atoi.o \
			includes/libft/ft_isalpha.o \
			includes/libft/ft_isdigit.o \
			includes/libft/ft_isalnum.o \
			includes/libft/ft_isascii.o \
			includes/libft/ft_isprint.o \
			includes/libft/ft_toupper.o \
			includes/libft/ft_tolower.o \
			includes/libft/ft_memalloc.o \
			includes/libft/ft_memdel.o \
			includes/libft/ft_strnew.o \
			includes/libft/ft_strdel.o \
			includes/libft/ft_strclr.o \
			includes/libft/ft_striter.o \
			includes/libft/ft_striteri.o \
			includes/libft/ft_strmap.o \
			includes/libft/ft_strmapi.o \
			includes/libft/ft_strequ.o \
			includes/libft/ft_strnequ.o \
			includes/libft/ft_strsub.o \
			includes/libft/ft_strjoin.o \
			includes/libft/ft_strtrim.o \
			includes/libft/ft_strsplit.o \
			includes/libft/ft_itoa.o \
			includes/libft/ft_putchar.o \
			includes/libft/ft_putstr.o \
			includes/libft/ft_putendl.o \
			includes/libft/ft_putnbr.o \
			includes/libft/ft_putchar_fd.o \
			includes/libft/ft_putstr_fd.o \
			includes/libft/ft_putendl_fd.o \
			includes/libft/ft_putnbr_fd.o \
			includes/libft/ft_lstnew.o	\
			includes/libft/ft_lstdelone.o \
			includes/libft/ft_lstdel.o \
			includes/libft/ft_lstadd.o \
			includes/libft/ft_lstiter.o \
			includes/libft/ft_lstmap.o \

RM = rm -f

LIBS = ./includes/libft/libft.a

all: $(NAME)

$(OBJS):
	gcc $(CFLAG) $(SRCS)

$(LIB_OBJS):
	$(MAKE) -C ./includes/libft
$(NAME): $(OBJS) $(LIB_OBJS)
	ar rcs $(NAME) $(LIB_OBJS) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./includes/libft/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./includes/libft/ fclean

re: fclean all

.PHONY: clean fclean re
