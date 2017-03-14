/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:35:20 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/13 18:35:21 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_printf_u_z(va_list ap, t_param *params)
{
	size_t		n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, size_t);
	nbr = ft_itoa_base(n, 10);
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

size_t	ft_printf_u_j(va_list ap, t_param *params)
{
	uintmax_t	n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, uintmax_t);
	nbr = ft_itoa_base(n, 10);
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

size_t	ft_printf_u_ll(va_list ap, t_param *params)
{
	unsigned long long int	n;
	char			*nbr;
	size_t			length;

	length = 0;
	n = va_arg(ap, unsigned long long int);
	nbr = ft_itoa_base(n, 10);
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
