/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_add_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:07:10 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 20:08:49 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_add_last(t_dlst *list, void *element)
{
	t_dnode	*node;

	node = list->mem_calloc(1, sizeof(t_dnode));
	if (node == NULL)
		return (LST_ERR_ALLOC);
	node->data = element;
	if (list->size == 0)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
	list->size++;
	return (LST_OK);
}
