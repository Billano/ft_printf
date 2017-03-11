/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:23:42 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:23:43 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size(t_list_a *begin_list)
{
	t_list_a	*head;
	int			n;

	n = 0;
	head = begin_list;
	while (head)
	{
		n++;
		head = head->next;
	}
	return (n);
}
