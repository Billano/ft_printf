/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 21:33:06 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/14 21:33:08 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_printf_o_l(va_list ap, t_param *params)
{
	unsigned long int	n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, unsigned long int);
	nbr = ft_uitoa_base(n, 8);
	length = ft_strlen(nbr);
	if (ft_printf_str_contains(params->flags, '#') && length == 1 && *nbr == '0')
		params->sign = -1;
	if (ft_printf_str_contains(params->flags, '#'))
		length += 1;
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_o_h(va_list ap, t_param *params)
{
	unsigned int			n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, unsigned int);
	nbr = ft_uitoa_base(n, 8);
	length = ft_strlen(nbr);
	if (ft_printf_str_contains(params->flags, '#') && length == 1 && *nbr == '0')
		params->sign = -1;
	if (ft_printf_str_contains(params->flags, '#'))
		length += 1;
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_o_hh(va_list ap, t_param *params)
{
	unsigned int			n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, unsigned int);
	nbr = ft_uitoa_base(n, 8);
	length = ft_strlen(nbr);
	if (ft_printf_str_contains(params->flags, '#') && length == 1 && *nbr == '0')
		params->sign = -1;
	if (ft_printf_str_contains(params->flags, '#'))
		length += 1;
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_o_i(va_list ap, t_param *params)
{
	unsigned int			n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, unsigned int);
	nbr = ft_uitoa_base(n, 8);
	length = ft_strlen(nbr);
	if (ft_printf_str_contains(params->flags, '#') && length == 1 && *nbr == '0')
		params->sign = -1;
	if (ft_printf_str_contains(params->flags, '#'))
		length += 1;
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_o(va_list ap, t_param *params)
{
	size_t		length;

	length = 0;
	if (ft_strcmp(params->length, "h") == 0)
		length += ft_printf_o_h(ap, params);
	else if (ft_strcmp(params->length, "hh") == 0)
		length += ft_printf_o_hh(ap, params);
	else if (ft_strcmp(params->length, "l") == 0)
		length += ft_printf_o_l(ap, params);
	else if (ft_strcmp(params->length, "ll") == 0)
		length += ft_printf_o_ll(ap, params);
	else if (ft_strcmp(params->length, "j") == 0)
		length += ft_printf_o_j(ap, params);
	else if (ft_strcmp(params->length, "z") == 0)
		length += ft_printf_o_z(ap, params);
	else
		length += ft_printf_o_i(ap, params);
	return (length);
}
