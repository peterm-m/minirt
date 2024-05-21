/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:50:52 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/07 16:25:12 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

void	*unlink(t_dlst *list, t_dnode *node)
{
	void	*data;

	data = node->data;
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->prev == NULL)
		list->head = node->next;
	if (node->next == NULL)
		list->tail = node->prev;
	if (node->next != NULL)
		node->next->prev = node->prev;
	list->mem_free(node);
	list->size--;
	return (data);
}
