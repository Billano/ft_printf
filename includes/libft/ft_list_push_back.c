/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:22:46 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:22:48 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list_a **begin_list, void *data)
{
	t_list_a *head;

	if (!(*begin_list))
	{
		*begin_list = ft_create_elem(data);
	}
	else
	{
		head = *begin_list;
		while (head->next)
			head = head->next;
		head->next = ft_create_elem(data);
	}
}
