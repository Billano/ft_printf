/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 06:34:02 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/11 06:34:03 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t ft_printf_d(va_list ap, t_param *params)
{
	int n;

	n = va_arg(ap, int);
	params->width = 0;
	ft_putstr(ft_itoa_base(n, 10));
	return (1);
}
