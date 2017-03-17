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
# include <limits.h>

typedef struct		s_param
{
  char    *flags;
  size_t  width;
  size_t  precision;
  char    *length;
	int 		sign;
	int			symbol;
	size_t 	strlen;
	char		specifier;
	int			precision_flag;
}					t_param;

int ft_printf(const char *format, ...);

// Extract parameters

int ft_specifier_printf(char c);
char *ft_printf_str_trim(const char *str);
t_param *ft_printf_params_init(char *str, va_list ap);
char	*ft_printf_flags(char *str);
size_t	ft_printf_width(char *str, va_list ap);
size_t	ft_printf_precision(char *str, va_list ap);
char	*ft_printf_length(char *str);
int	ft_printf_precision_flag(char *str);
int	ft_printf_symbol(char *flags);

// %
size_t	ft_printf_percent(t_param *params);

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

// d, D, i, I
void ft_print_d(t_param *params, size_t length, char *nbr);
size_t ft_printf_d(va_list ap, t_param *params);
size_t ft_printf_d_i(va_list ap, t_param *params);
size_t ft_printf_d_h(va_list ap, t_param *params);
size_t ft_printf_d_hh(va_list ap, t_param *params);
size_t ft_printf_d_l(va_list ap, t_param *params);
size_t ft_printf_d_ll(va_list ap, t_param *params);
size_t ft_printf_d_j(va_list ap, t_param *params);
size_t ft_printf_d_z(va_list ap, t_param *params);
// u
size_t ft_printf_u(va_list ap, t_param *params);
size_t ft_printf_u_i(va_list ap, t_param *params);
size_t ft_printf_u_h(va_list ap, t_param *params);
size_t ft_printf_u_hh(va_list ap, t_param *params);
size_t ft_printf_u_l(va_list ap, t_param *params);
size_t ft_printf_u_ll(va_list ap, t_param *params);
size_t ft_printf_u_j(va_list ap, t_param *params);
size_t ft_printf_u_z(va_list ap, t_param *params);

// o
size_t ft_printf_o(va_list ap, t_param *params);
size_t ft_printf_o_i(va_list ap, t_param *params);
size_t ft_printf_o_h(va_list ap, t_param *params);
size_t ft_printf_o_hh(va_list ap, t_param *params);
size_t ft_printf_o_l(va_list ap, t_param *params);
size_t ft_printf_o_ll(va_list ap, t_param *params);
size_t ft_printf_o_j(va_list ap, t_param *params);
size_t ft_printf_o_z(va_list ap, t_param *params);

// x
size_t ft_printf_x(va_list ap, t_param *params);
size_t ft_printf_x_i(va_list ap, t_param *params);
size_t ft_printf_x_h(va_list ap, t_param *params);
size_t ft_printf_x_hh(va_list ap, t_param *params);
size_t ft_printf_x_l(va_list ap, t_param *params);
size_t ft_printf_x_ll(va_list ap, t_param *params);
size_t ft_printf_x_j(va_list ap, t_param *params);
size_t ft_printf_x_z(va_list ap, t_param *params);
// X = lx
size_t ft_printf_lx(va_list ap, t_param *params);
size_t ft_printf_lx_i(va_list ap, t_param *params);
size_t ft_printf_lx_h(va_list ap, t_param *params);
size_t ft_printf_lx_hh(va_list ap, t_param *params);
size_t ft_printf_lx_l(va_list ap, t_param *params);
size_t ft_printf_lx_ll(va_list ap, t_param *params);
size_t ft_printf_lx_j(va_list ap, t_param *params);
size_t ft_printf_lx_z(va_list ap, t_param *params);

// n

void ft_printf_n_size_t(va_list ap,size_t length);
void ft_printf_n_intmax_t(va_list ap,size_t length);
void ft_printf_n_l_l_int(va_list ap,size_t length);
void ft_printf_n_l_int(va_list ap,size_t length);
void ft_printf_n_int(va_list ap,size_t length);
void ft_printf_n(va_list ap, t_param *params, size_t length);


//flags
void	ft_print_blank_s(t_param *params, size_t length);
void	ft_print_blank_d(t_param *params, size_t length);
void	ft_print_blank_d_zero(t_param *params, size_t length);
void ft_print_sign(t_param *params);
void ft_print_zero(t_param *params, size_t length);

// Extras/Utilities gcc -Wall -Werror -Wextra -c $(SRCS) -I /includes/
int	ft_printf_str_contains(char *str, char c);
void	ft_putchar_n_bytes(wchar_t c, size_t n);
size_t	ft_wstrlen(wchar_t *str);
char	*ft_itoa_base(long long int value, int base);
char	*ft_uitoa_base(unsigned long long int value, int base);
char	*ft_uitoa_base_l(unsigned long long int value, int base);
#endif
