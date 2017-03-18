/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:53:20 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/13 18:24:50 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_printf_print_lc(wchar_t n)
{
	if (n <= 0x7F)
		ft_putchar(n);
	else if (n <= 0x7FF)
	{
		ft_putchar((n >> 6) + 0xC0);
		ft_putchar((n & 0x3F) + 0x80);
	}
	else if (n <= 0xFFFF)
	{
		ft_putchar((n >> 12) + 0xE0);
		ft_putchar(((n >> 6) & 0x3F) + 0x80);
		ft_putchar((n & 0x3F) + 0x80);
	}
	else if (n <= 0x10FFFF)
	{
		ft_putchar((n >> 18) + 0xF0);
		ft_putchar(((n >> 12) & 0x3F) + 0x80);
		ft_putchar(((n >> 6) & 0x3F) + 0x80);
		ft_putchar((n & 0x3F) + 0x80);
	}
	// if (n <= 127)
	// 	ft_putchar_n_bytes(n, 1);
	// else if (n <= 2047)
	// 	ft_putchar_n_bytes(n, 2);
	// else if (n <= 65535)
	// 	ft_putchar_n_bytes(n, 3);
	// else if (n <= 1114111)
	// 	ft_putchar_n_bytes(n, 4);
}

size_t	ft_printf_lc(va_list ap, t_param *params)
{
	wchar_t			n;

	n = (wchar_t)va_arg(ap, wint_t);
	if (ft_printf_str_contains(params->flags, '-'))
	{
		ft_printf_print_lc(n);
		ft_print_blank_s(params, 1);
	}
	else
	{
		ft_print_blank_s(params, 1);
		ft_printf_print_lc(n);
	}
	return (ft_max_number(params->width, 1));
}

size_t	ft_printf_c(va_list ap, t_param *params)
{
	int				n;
	unsigned char	c;

	if (*(params->length) != 'l')
	{
		n = va_arg(ap, int);
		c = (unsigned char)n;
		if (ft_printf_str_contains(params->flags, '-'))
		{
			ft_putchar(c);
			ft_print_blank_s(params, 1);
		}
		else
		{
			ft_print_blank_s(params, 1);
			ft_putchar(c);
		}
		return (ft_max_number(params->width, 1));
	}
	return (ft_printf_lc(ap, params));
}
