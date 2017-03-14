/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_blank.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 05:25:20 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/09 05:25:22 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_print_blank_d(t_param *params, size_t length)
{
	size_t i;

	i = 0;
	if (params->width > length && params->width > params->precision)
	{
		if (params->precision < length)
		{
			while (i < (params->width - length - params->sign))
			{
				ft_putchar(' ');
				i++;
			}
		}
		else
		{
			while (i < (params->width - params->precision - params->sign))
			{
				ft_putchar(' ');
				i++;
			}
		}
	}
}

void	ft_print_blank_s(t_param *params, size_t length)
{
	size_t i;

	i = 0;
	if (params->width > length)
	{
		while (i < params->width - length)
		{
			ft_putchar(' ');
			i++;
		}
	}
}
