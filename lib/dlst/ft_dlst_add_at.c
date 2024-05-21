/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_add_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:16:05 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 21:16:10 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_add_at(t_dlst *list, void *element, size_t index)
{
	t_dnode		*base;
	t_dlst_stat	stat;
	t_dnode		*new;

	stat = get_node_at(list, index, &base);
	if (stat != LST_OK)
		return (stat);
	new = list->mem_calloc(1, sizeof(t_dnode));
	if (!new)
		return (LST_ERR_ALLOC);
	new->data = element;
	link_behind(base, new);
	if (index == 0)
		list->head = new;
	list->size++;
	return (LST_OK);
}
