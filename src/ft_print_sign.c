/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:22:38 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/13 18:25:08 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_print_sign(t_param *params)
{
	if (ft_printf_str_contains(params->flags, '#'))
	{
		if (params->specifier == 'o')
			ft_putstr("0");
		else if (params->specifier == 'x')
			ft_putstr("0x");
		else if (params->specifier == 'X')
			ft_putstr("0X");
		if (params->specifier == 'p')
			ft_putstr("0x");
		else if (params->specifier == 'P')
			ft_putstr("0x7ff");
	}
	else if (params->sign == 0 && ft_printf_str_contains(params->flags, '+'))
		ft_putchar('+');
	else if (params->sign == 0 && ft_printf_str_contains(params->flags, ' '))
		ft_putchar(' ');
	else if (params->sign == 1)
		ft_putchar('-');
}
