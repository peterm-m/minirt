/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:51:25 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 19:51:37 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	get_node_at(t_dlst *list, size_t index, t_dnode **out)
{
	size_t	i;
	t_dnode	*node;

	if (!list || index >= list->size)
		return (LST_ERR_OUT_OF_RANGE);
	node = NULL;
	if (index < list->size / 2)
	{
		node = list->head;
		i = 0;
		while (i++ < index)
			node = node->next;
	}
	else
	{
		node = list->tail;
		i = list->size - 1;
		while (i-- > index)
			node = node->prev;
	}
	*out = node;
	return (LST_OK);
}
