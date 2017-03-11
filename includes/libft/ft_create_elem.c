/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:12:05 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:12:07 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_a	*ft_create_elem(void *data)
{
	t_list_a *lst;

	lst = NULL;
	if (!(lst = (t_list_a *)malloc(sizeof(t_list_a))))
		return (NULL);
	lst->data = data;
	lst->next = NULL;
	return (lst);
}
