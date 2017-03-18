/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 22:01:12 by eurodrig          #+#    #+#             */
/*   Updated: 2017/02/08 00:55:50 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list ap;
	char *s;
	size_t trimmed_length;
	size_t	str_length;
	t_param *params;

	va_start(ap, format);
	str_length = 0;
	params = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			s = ft_printf_str_trim(format);
			trimmed_length = ft_strlen(s);
			params = ft_printf_params_init(s, ap);
			trimmed_length = ft_strlen(s);
			if (*s && s[trimmed_length - 1] == '%')
				str_length += ft_printf_percent(params);
			else if (*s && s[trimmed_length - 1] == 's')
				str_length += ft_printf_s(ap, params);
			else if (*s && s[trimmed_length - 1] == 'S')
				str_length += ft_printf_ls(ap, params);
			else if (*s && s[trimmed_length - 1] == 'c')
				str_length += ft_printf_c(ap, params);
			else if (*s && s[trimmed_length - 1] == 'C')
				str_length += ft_printf_lc(ap, params);
			else if (*s && (s[trimmed_length - 1] == 'd' || s[trimmed_length - 1] == 'i'))
				str_length += ft_printf_d(ap, params);
			else if (*s && s[trimmed_length - 1] == 'D')
				str_length += ft_printf_d_l_int(ap, params);
			else if (*s && s[trimmed_length - 1] == 'u')
				str_length += ft_printf_u(ap, params);
			else if (*s && s[trimmed_length - 1] == 'U')
				str_length += ft_printf_u_l_int(ap, params);
			else if (*s && s[trimmed_length - 1] == 'o')
				str_length += ft_printf_o(ap, params);
			else if (*s && s[trimmed_length - 1] == 'O')
				str_length += ft_printf_o_l_int(ap, params);
			else if (*s && s[trimmed_length - 1] == 'x')
				str_length += ft_printf_x(ap, params);
			else if (*s && s[trimmed_length - 1] == 'X')
				str_length += ft_printf_lx(ap, params);
			else if (*s && s[trimmed_length - 1] == 'p')
			{
				params->flags = ft_strcat(params->flags, "ll#");
				str_length += ft_printf_x_l_int(ap, params);
			}
			else if (*s && s[trimmed_length - 1] == 'n')
				ft_printf_n(ap, params, str_length);
			else
				va_arg(ap, void *);
			format += trimmed_length;
			ft_multiple_memdel("4", (void **)&(params->flags),
			(void **)&(params->length), (void **)&params, (void **)&s);
		}
		if (!*format)
			break ;
		if (*format != '%')
		{
			ft_putchar(*format);
			str_length += 1;
			format++;
		}
	}
	va_end(ap);
	return (str_length);
}
