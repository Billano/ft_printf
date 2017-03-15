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
	t_param *params = NULL;

	va_start(ap, format);
	str_length = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			s = ft_printf_str_trim(format);
			params = ft_printf_params_init(s);
			trimmed_length = ft_strlen(s);
			if (*s && s[trimmed_length - 1] == '%')
			{
				ft_putstr(s);
				str_length += trimmed_length;
			}
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
					str_length += ft_printf_d_l(ap, params);
			else if (*s && s[trimmed_length - 1] == 'u')
				str_length += ft_printf_u(ap, params);
			else if (*s && s[trimmed_length - 1] == 'U')
				str_length += ft_printf_u_l(ap, params);
			else if (*s && s[trimmed_length - 1] == 'o')
				str_length += ft_printf_o(ap, params);
			else if (*s && s[trimmed_length - 1] == 'O')
				str_length += ft_printf_o_l(ap, params);
			else if (*s && s[trimmed_length - 1] == 'x')
				str_length += ft_printf_x(ap, params);
			else if (*s && s[trimmed_length - 1] == 'X')
				str_length += ft_printf_lx(ap, params);
			else
				va_arg(ap, void *);

			format += trimmed_length;
		}
		str_length += 1;
		if (!*format)
			break;
		if (*format != '%')
		{
		ft_putchar(*format);
		format++;
		}
	}
	va_end(ap);
	return (str_length);
}

// int	main()
// {
// 	printf("%s\n", "Hola");
// 	ft_printf("%s\n", "Hola");
// 	return (0);
// }
//gcc -Wall -Werror -Wextra $(SRCS) ./includes/libft/libft.a -I includes/libft/ -o executable
