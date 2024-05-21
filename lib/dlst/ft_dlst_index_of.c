/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_index_of.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:03:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 20:03:36 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_index_of(t_dlst *list, void *element,
	int (*cmp)(const void*, const void*), size_t *index)
{
	t_dnode		*node;
	size_t		i;

	node = list->head;
	i = 0;
	while (node)
	{
		if (cmp(node->data, element) == 0)
		{
			*index = i;
			return (LST_OK);
		}
		i++;
		node = node->next;
	}
	return (LST_ERR_OUT_OF_RANGE);
}
