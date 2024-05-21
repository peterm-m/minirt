/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_iter_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:04:14 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 20:04:47 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_iter_add(t_dlst_iter *iter, void *element)
{
	t_dnode	*new_node;

	new_node = iter->list->mem_calloc(1, sizeof(t_dnode));
	if (!new_node)
		return (LST_ERR_ALLOC);
	new_node->data = element;
	link_after(iter->last, new_node);
	if (iter->index == iter->list->size)
		iter->list->tail = new_node;
	iter->list->size++;
	iter->index++;
	return (LST_OK);
}
