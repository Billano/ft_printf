/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 21:41:27 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/14 21:41:29 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_printf_x_l(va_list ap, t_param *params)
{
	unsigned long int	n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, unsigned long int);
	nbr = ft_uitoa_base_l(n, 16);
	length = ft_strlen(nbr);
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_x_h(va_list ap, t_param *params)
{
	unsigned int			n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, unsigned int);
	nbr = ft_uitoa_base_l(n, 16);
	length = ft_strlen(nbr);
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_x_hh(va_list ap, t_param *params)
{
	unsigned int			n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, unsigned int);
	nbr = ft_uitoa_base_l(n, 16);
	length = ft_strlen(nbr);
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_x_i(va_list ap, t_param *params)
{
	unsigned int			n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, unsigned int);
	if (n > 32768)
		params->specifier = 'P';
	nbr = ft_uitoa_base_l(n, 16);
	length = ft_strlen(nbr);
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_x(va_list ap, t_param *params)
{
	size_t		length;

	length = 0;
	if (ft_strcmp(params->length, "h") == 0)
		length += ft_printf_x_h(ap, params);
	else if (ft_strcmp(params->length, "hh") == 0)
		length += ft_printf_x_hh(ap, params);
	else if (ft_strcmp(params->length, "l") == 0)
		length += ft_printf_x_l(ap, params);
	else if (ft_strcmp(params->length, "ll") == 0)
		length += ft_printf_x_ll(ap, params);
	else if (ft_strcmp(params->length, "j") == 0)
		length += ft_printf_x_j(ap, params);
	else if (ft_strcmp(params->length, "z") == 0)
		length += ft_printf_x_z(ap, params);
	else
		length += ft_printf_x_i(ap, params);
	return (length);
}
