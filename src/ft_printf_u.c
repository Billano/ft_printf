/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:28:17 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/13 18:28:19 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_printf_u_l(va_list ap, t_param *params)
{
	unsigned long int	n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, unsigned long int);
	nbr = ft_uitoa_base(n, 10);
	length = ft_strlen(nbr);
	if (ft_printf_str_contains(params->flags, '-') == 1)
	{
		ft_print_sign(params, length);
		ft_print_zero(params, length);
		ft_putstr(nbr);
		ft_print_blank_d(params, length);
	}
	else
	{
		ft_print_blank_d(params, length);
		ft_print_sign(params, length);
		ft_print_zero(params, length);
		ft_putstr(nbr);
	}
	return (length);
}

size_t	ft_printf_u_h(va_list ap, t_param *params)
{
	unsigned int			n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, unsigned int);
	nbr = ft_uitoa_base(n, 10);
	length = ft_strlen(nbr);
	if (ft_printf_str_contains(params->flags, '-') == 1)
	{
		ft_print_sign(params, length);
		ft_print_zero(params, length);
		ft_putstr(nbr);
		ft_print_blank_d(params, length);
	}
	else
	{
		ft_print_blank_d(params, length);
		ft_print_sign(params, length);
		ft_print_zero(params, length);
		ft_putstr(nbr);
	}
	return (length);
}

size_t	ft_printf_u_hh(va_list ap, t_param *params)
{
	unsigned int			n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, unsigned int);
	nbr = ft_uitoa_base(n, 10);
	length = ft_strlen(nbr);
	if (ft_printf_str_contains(params->flags, '-') == 1)
	{
		ft_print_sign(params, length);
		ft_print_zero(params, length);
		ft_putstr(nbr);
		ft_print_blank_d(params, length);
	}
	else
	{
		ft_print_blank_d(params, length);
		ft_print_sign(params, length);
		ft_print_zero(params, length);
		ft_putstr(nbr);
	}
	return (length);
}

size_t	ft_printf_u_i(va_list ap, t_param *params)
{
	unsigned int			n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, unsigned int);
	nbr = ft_uitoa_base(n, 10);
	length = ft_strlen(nbr);
	if (ft_printf_str_contains(params->flags, '-') == 1)
	{
		ft_print_sign(params, length);
		ft_print_zero(params, length);
		ft_putstr(nbr);
		ft_print_blank_d(params, length);
	}
	else
	{
		ft_print_blank_d(params, length);
		ft_print_sign(params, length);
		ft_print_zero(params, length);
		ft_putstr(nbr);
	}
	return (length);
}

size_t	ft_printf_u(va_list ap, t_param *params)
{
	size_t		length;

	length = 0;
	if (ft_strcmp(params->length, "h"))
		length += ft_printf_u_h(ap, params);
	else if (ft_strcmp(params->length, "hh"))
		length += ft_printf_u_hh(ap, params);
	else if (ft_strcmp(params->length, "l"))
		length += ft_printf_u_l(ap, params);
	else if (ft_strcmp(params->length, "ll"))
		length += ft_printf_u_ll(ap, params);
	else if (ft_strcmp(params->length, "j"))
		length += ft_printf_u_j(ap, params);
	else if (ft_strcmp(params->length, "z"))
		length += ft_printf_u_z(ap, params);
	else
		length += ft_printf_u_i(ap, params);
	return (length);
}
