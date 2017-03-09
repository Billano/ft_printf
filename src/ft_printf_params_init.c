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

t_param	ft_printf_params_init(char *str)
{
	t_param params;

	params.flags = ft_printf_flags(str);
	params.width = ft_printf_width(str);
	params.precision = ft_printf_precision(str);
	params.length = ft_printf_length(str);
	return (params);
}
