/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:54:15 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/14 20:54:15 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_print_d(t_param *params, size_t length, char *nbr)
{
	if (ft_printf_str_contains(params->flags, '-') == 1)
	{
		ft_print_sign(params);
		ft_print_zero(params, length);
		ft_putstr(nbr);
		ft_print_blank_d(params, length);
	}
	else
	{
		ft_print_blank_d(params, length);
		ft_print_sign(params);
		ft_print_zero(params, length);
		ft_putstr(nbr);
	}
}

size_t	ft_printf_d_z(va_list ap, t_param *params)
{
	size_t		n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, size_t);
	nbr = ft_itoa_base(n, 10);
	length = ft_strlen(nbr);
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_d_j(va_list ap, t_param *params)
{
	intmax_t	n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, intmax_t);
	if (n < 0)
		params->sign = 1;
	nbr = ft_itoa_base(n, 10);
	length = ft_strlen(nbr);
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_d_ll(va_list ap, t_param *params)
{
	long long int	n;
	char			*nbr;
	size_t			length;

	length = 0;
	n = va_arg(ap, long long int);
	if (n < 0)
		params->sign = 1;
	nbr = ft_itoa_base(n, 10);
	length = ft_strlen(nbr);
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}
