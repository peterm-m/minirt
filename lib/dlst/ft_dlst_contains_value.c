/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_contains_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:15:13 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 21:15:21 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

size_t	ft_dlst_contains_value(t_dlst *list, void *element,
	int (*cmp)(const void*, const void*))
{
	t_dnode	*node;
	size_t	e_count;

	e_count = 0;
	node = list->head;
	while (node)
	{
		if (cmp(node->data, element) == 0)
			e_count++;
		node = node->next;
	}
	return (e_count);
}
