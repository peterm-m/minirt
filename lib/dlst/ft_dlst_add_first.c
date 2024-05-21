/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_add_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:24:17 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/07 16:07:42 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_add_first(t_dlst *list, void *element)
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
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	list->size++;
	return (LST_OK);
}
