/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_splice_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:11:30 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 20:11:39 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

static void	fuction_auxiliar(t_dlst *list1, t_dlst *list2)
{
	list1->head = list2->head;
	list1->tail = list2->tail;
	list1->size = list2->size;
	list2->head = NULL;
	list2->tail = NULL;
	list2->size = 0;
}

t_dlst_stat	ft_dlst_splice_at(t_dlst *list1, t_dlst *list2, size_t index)
{
	t_dnode	*end;
	t_dnode	*base;

	if (list2->size == 0)
		return (LST_OK);
	if (index > list1->size)
		return (LST_ERR_OUT_OF_RANGE);
	if (list1->size == 0)
	{
		fuction_auxiliar(list1, list2);
		return (LST_OK);
	}
	end = NULL;
	get_node_at(list1, index, &end);
	base = NULL;
	if (end)
		base = end->prev;
	else
		get_node_at(list1, index - 1, &base);
	splice_between(list1, list2, base, end);
	return (LST_OK);
}
