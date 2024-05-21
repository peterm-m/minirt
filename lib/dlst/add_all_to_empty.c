/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_all_to_empty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:53:49 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 19:54:30 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	add_all_to_empty(t_dlst *list1, t_dlst *list2)
{
	t_dnode	*head;
	t_dnode	*tail;

	if (list2->size == 0)
		return (LST_OK);
	head = NULL;
	tail = NULL;
	if (!link_all_externally(list2, &head, &tail))
		return (LST_ERR_ALLOC);
	list1->head = head;
	list1->tail = tail;
	list1->size = list2->size;
	return (LST_OK);
}
