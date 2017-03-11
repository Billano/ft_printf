/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 22:03:53 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/30 22:03:59 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>

typedef struct		s_param
{
  char    *flags;
  size_t  width;
  size_t  precision;
  char    *length;
}					t_param;

int ft_printf(const char *format, ...);

// Extract parameters

int ft_specifier_printf(char c);
char *ft_printf_str_trim(const char *str);
t_param *ft_printf_params_init(char *str);
char	*ft_printf_flags(char *str);
size_t	ft_printf_width(char *str);
size_t	ft_printf_precision(char *str);
char	*ft_printf_length(char *str);

// s, S
void ft_printf_print_lsp(t_param *params, wchar_t *str);
void ft_printf_print_ls(wchar_t *str);
size_t ft_printf_ls(va_list ap, t_param *params);
void ft_printf_print_s(t_param *params, char *str);
size_t ft_printf_s(va_list ap, t_param *params);

// c, C
void	ft_printf_print_lc(wint_t n);
size_t	ft_printf_lc(va_list ap, t_param *params);
size_t	ft_printf_c(va_list ap, t_param *params);

//flags
void	ft_print_blank(t_param *params, size_t length);

// Extras/Utilities gcc -Wall -Werror -Wextra -c $(SRCS) -I /includes/
int	ft_printf_str_contains(char *str, char c);
void	ft_putchar_n_bytes(wint_t c, size_t n);
size_t	ft_wstrlen(wchar_t *str);

#endif
