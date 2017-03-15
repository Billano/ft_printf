/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 06:34:02 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/13 18:15:03 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_printf_d_l(va_list ap, t_param *params)
{
	long int	n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, long int);
	if (n < 0)
		params->sign = 1;
	nbr = ft_itoa_base(n, 10);
	length = ft_strlen(nbr);
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_d_h(va_list ap, t_param *params)
{
	int			n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, int);
	if (n < 0)
		params->sign = 1;
	nbr = ft_itoa_base(n, 10);
	length = ft_strlen(nbr);
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_d_hh(va_list ap, t_param *params)
{
	int			n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, int);
	if (n < 0)
		params->sign = 1;
	nbr = ft_itoa_base(n, 10);
	length = ft_strlen(nbr);
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_d_i(va_list ap, t_param *params)
{
	int			n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, int);
	if (n < 0)
		params->sign = 1;
	nbr = ft_itoa_base(n, 10);
	length = ft_strlen(nbr);
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_d(va_list ap, t_param *params)
{
	size_t		length;

	length = 0;
	if (ft_strcmp(params->length, "h") == 0)
		length += ft_printf_d_h(ap, params);
	else if (ft_strcmp(params->length, "hh") == 0)
		length += ft_printf_d_hh(ap, params);
	else if (ft_strcmp(params->length, "l") == 0)
		length += ft_printf_d_l(ap, params);
	else if (ft_strcmp(params->length, "ll") == 0)
		length += ft_printf_d_ll(ap, params);
	else if (ft_strcmp(params->length, "j") == 0)
		length += ft_printf_d_j(ap, params);
	else if (ft_strcmp(params->length, "z") == 0)
		length += ft_printf_d_z(ap, params);
	else
		length += ft_printf_d_i(ap, params);
	return (length);
}
