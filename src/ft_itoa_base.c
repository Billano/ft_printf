/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 06:32:12 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/13 18:27:44 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	aux_u(unsigned long long int n, unsigned long long int b, char *ans,\
	unsigned long long int *p)
{
	char					base[] = "0123456789ABCDEF";

	if (n <= -b || b <= n)
		aux_u(n / b, b, ans, p);
	ans[(*p)++] = base[ABS(n % b)];
}

char	*ft_uitoa_base(unsigned long long int value,\
		unsigned long long int base)
{
	char					*ans;
	unsigned long long int	p;

	if (base < 2 || 16 < base
		|| !(ans = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	aux_u(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}

void	aux(long long n, long long b, char *ans, long long *p)
{
	char					base[] = "0123456789ABCDEF";

	if (n <= -b || b <= n)
		aux(n / b, b, ans, p);
	ans[(*p)++] = base[ABS(n % b)];
}

char	*ft_itoa_base(long long value, long long base)
{
	char					*ans;
	long long				p;

	if (base < 2 || 16 < base
		|| !(ans = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	if (base == 10 && value < 0)
		;
	aux(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
