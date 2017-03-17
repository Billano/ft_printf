/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 03:28:00 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/09 03:28:01 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_printf_precision_flag(char *str)
{
	return (ft_str_includes(str, '.') ? 1: 0);
}

size_t	ft_printf_precision(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			break ;
		i++;
	}
	if (!str[i])
		return (0);
	return (ft_atoi(str + i + 1));
}
