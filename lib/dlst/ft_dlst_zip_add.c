/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_zip_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:58:12 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 20:58:24 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_zip_add(t_dlst_zip *iter, void *e1, void *e2)
{
	t_dnode	*new_node2;
	t_dnode	*new_node1;

	new_node1 = iter->l1->mem_calloc(1, sizeof(t_dnode));
	if (!new_node1)
		return (LST_ERR_ALLOC);
	new_node2 = iter->l2->mem_calloc(1, sizeof(t_dnode));
	if (!new_node2)
	{
		iter->l1->mem_free(new_node1);
		return (LST_ERR_ALLOC);
	}
	new_node1->data = e1;
	new_node2->data = e2;
	link_after(iter->l1_last, new_node1);
	link_after(iter->l2_last, new_node2);
	if (iter->index == iter->l1->size)
		iter->l1->tail = new_node1;
	if (iter->index == iter->l2->size)
		iter->l2->tail = new_node2;
	iter->l1->size++;
	iter->l2->size++;
	iter->index++;
	return (LST_OK);
}
