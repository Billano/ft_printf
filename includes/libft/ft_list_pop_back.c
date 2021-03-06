/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:22:17 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:22:19 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_a	*ft_list_pop_back(t_list_a **begin_list)
{
	t_list_a *head;
	t_list_a *ret;

	head = *begin_list;
	while ((head->next)->next)
		head = head->next;
	ret = head->next;
	head->next = NULL;
	return (ret);
}
