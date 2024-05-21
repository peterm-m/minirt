/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_add_all_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:28:32 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/07 16:54:08 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

static void	ft_dlst_add_all_at_aux(t_dlst *list1, t_dnode **nodes)
{
	if (!nodes[2])
	{
		list1->tail->next = nodes[0];
		nodes[0]->prev = list1->tail;
		list1->tail = nodes[1];
	}
	else if (!nodes[3])
	{
		list1->head->prev = nodes[1];
		nodes[1]->next = list1->head;
		list1->head = nodes[0];
	}
	else
	{
		nodes[0]->prev = nodes[3];
		nodes[3]->next = nodes[0];
		nodes[1]->next = nodes[2];
		nodes[2]->prev = nodes[1];
	}
}

t_dlst_stat	ft_dlst_add_all_at(t_dlst *list1, t_dlst *list2, size_t index)
{
	t_dnode	*nodes[4];

	if (list2->size == 0)
		return (LST_OK);
	if (index > list1->size)
		return (LST_ERR_OUT_OF_RANGE);
	nodes[0] = NULL;
	nodes[1] = NULL;
	if (!link_all_externally(list2, &nodes[0], &nodes[1]))
		return (LST_ERR_ALLOC);
	nodes[2] = NULL;
	get_node_at(list1, index, &nodes[2]);
	nodes[3] = NULL;
	if (nodes[2])
		nodes[3] = nodes[2]->prev;
	else
		get_node_at(list1, index - 1, &nodes[3]);
	ft_dlst_add_all_at_aux(list1, nodes);
	list1->size += list2->size;
	return (LST_OK);
}
