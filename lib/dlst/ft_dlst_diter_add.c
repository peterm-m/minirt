/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_diter_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:11:51 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 21:12:13 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_diter_add(t_dlst_iter *iter, void *element)
{
	t_dnode	*new_node;

	new_node = iter->list->mem_calloc(1, sizeof(t_dnode));
	if (!new_node)
		return (LST_ERR_ALLOC);
	new_node->data = element;
	if (iter->index == 0)
		iter->list->head = new_node;
	link_behind(iter->last, new_node);
	iter->list->size++;
	iter->last = new_node;
	return (LST_OK);
}
