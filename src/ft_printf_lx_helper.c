/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lx_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 21:42:26 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/14 21:42:28 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_printf_lx_z(va_list ap, t_param *params)
{
	size_t		n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, size_t);
	nbr = ft_uitoa_base(n, 16);
	length = ft_strlen(nbr);
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_lx_j(va_list ap, t_param *params)
{
	uintmax_t	n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, uintmax_t);
	nbr = ft_uitoa_base(n, 16);
	length = ft_strlen(nbr);
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_lx_ll(va_list ap, t_param *params)
{
	unsigned long long int	n;
	char			*nbr;
	size_t			length;

	length = 0;
	n = va_arg(ap, unsigned long long int);
	nbr = ft_uitoa_base(n, 16);
	length = ft_strlen(nbr);
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}
