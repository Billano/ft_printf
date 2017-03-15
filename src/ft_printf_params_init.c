/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_params_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 02:45:19 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/09 02:45:25 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_param	*ft_printf_params_init(char *str)
{
	t_param *params;

	if (!(params = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	params->flags = ft_printf_flags(str);
	params->width = ft_printf_width(str);
	params->precision = ft_printf_precision(str);
	params->length = ft_printf_length(str);
	params->sign = 0;
	params->strlen = ft_strlen(str);
	params->specifier = str[params->strlen - 1];
	params->symbol = 0;
	if (ft_printf_str_contains(params->flags, '+') ||\
		ft_printf_str_contains(params->flags, ' '))
		params->symbol = 1;
	return (params);
}
