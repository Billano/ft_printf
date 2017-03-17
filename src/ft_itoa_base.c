/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 06:32:12 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/14 20:42:19 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_uitoa_base_l(unsigned long long int value, int base)
{
	unsigned long long int	tmp;
	char					*str;
	size_t					len;
	char					*nb;

	nb = ft_strdup("0123456789abcdef");
	if (value == 0 || base < 2 || base > 16)
		return ("0");
	tmp = value;
	len = 0;
	while (tmp > 0)
	{
		tmp /= base;
		len++;
	}
	str = ft_strnew(len);
	tmp = value;
	while (tmp && len--)
	{
		str[len] = nb[tmp % base];
		tmp /= base;
	}
	return (str);
}

char	*ft_uitoa_base(unsigned long long int value, int base)
{
	unsigned long long int	tmp;
	char					*str;
	size_t					len;
	char					*nb;

	nb = ft_strdup("0123456789ABCDEF");
	if (value == 0 || base < 2 || base > 16)
		return ("0");
	tmp = value;
	len = 0;
	while (tmp > 0)
	{
		tmp /= base;
		len++;
	}
	str = ft_strnew(len);
	tmp = value;
	while (tmp && len--)
	{
		str[len] = nb[tmp % base];
		tmp /= base;
	}
	return (str);
}

char	*ft_itoa_base(long long int value, int base)
{
	long long int			tmp;
	char					*str;
	size_t					len;
	char					*nb;

	nb = ft_strdup("0123456789ABCDEF");
	if (value == 0 || base < 2 || base > 16)
		return ("0");
	if (value < 0)
		value *= -1;
	tmp = value;
	len = 0;
	while (tmp > 0)
	{
		tmp /= base;
		len++;
	}
	str = ft_strnew(len);
	tmp = value;
	while (tmp && len--)
	{
		str[len] = nb[tmp % base];
		tmp /= base;
	}
	return (str);
}
