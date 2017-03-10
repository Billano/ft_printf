/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:53:20 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/09 18:53:23 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_printf_print_lc(wint_t n)
{
	if (n <= 127)
		ft_putchar(n);
	else if (n <= 2047)
		ft_putchar_n_bytes(n, 2);
	else if (n <= 65535)
		ft_putchar_n_bytes(n, 3);
	else if (n <= 2097151)
		ft_putchar_n_bytes(n, 4);
}

size_t	ft_printf_lc(va_list ap, t_param *params)
{
	wint_t	c;

	c = va_arg(ap, wint_t);
	if (ft_str_contains(params->flags, '-'))
	{
		ft_printf_print_lc(c);
		ft_print_blank(params, 1);
	}
	else
	{
		ft_print_blank(params, 1);
		ft_printf_print_lc(c);
	}
	return (ft_max_number(params->width, 1));
}

size_t	ft_printf_c(va_list ap, t_param *params)
{
	int c;

	if (*(params->length) != 'l')
	{
		c = va_arg(ap, int);
		if (ft_str_contains(params->flags, '-'))
		{
			ft_putchar(c);
			ft_print_blank(params, 1);
		}
		else
		{
			ft_print_blank(params, 1);
			ft_putchar(c);
		}
		return (ft_max_number(params->width, 1));
	}
	return (ft_printf_lc(ap, params));
}
