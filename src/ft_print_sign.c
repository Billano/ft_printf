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

void	ft_print_sign(t_param *params, size_t length)
{
	if (length > 0 && ft_printf_str_contains(params->flags, '+'))
		ft_putchar('+');
	else if (length > 0 && ft_printf_str_contains(params->flags, ' '))
		ft_putchar(' ');
	else if (params->sign == 0)
		return ;
	else
		ft_putchar('-');
}
