/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_sublist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:03:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/07 16:31:16 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

static t_dlst_stat	ft_dlst_sublist_loop(size_t start, size_t e, t_dlst *sub,
		t_dnode *node)
{
	t_dlst_stat	status;
	size_t		i;

	i = start;
	while (i++ <= e)
	{
		status = ft_dlst_add(sub, node->data);
		if (status != LST_OK)
		{
			ft_dlst_destroy(sub);
			return (status);
		}
		node = node->next;
	}
	return (status);
}

t_dlst_stat	ft_dlst_sublist(t_dlst *list, size_t b, size_t e, t_dlst **out)
{
	t_dlst_conf	conf;
	t_dlst		*sub;
	t_dnode		*node;
	t_dlst_stat	status;

	if (b > e || e >= list->size)
		return (LST_ERR_INVALID_RANGE);
	conf.mem_alloc = list->mem_alloc;
	conf.mem_calloc = list->mem_calloc;
	conf.mem_free = list->mem_free;
	status = ft_dlst_new_conf(&conf, &sub);
	if (status != LST_OK)
		return (status);
	status = get_node_at(list, b, &node);
	if (status != LST_OK)
	{
		list->mem_free(sub);
		return (status);
	}
	status = ft_dlst_sublist_loop(b, e, sub, node);
	if (status != LST_OK)
		return (status);
	*out = sub;
	return (LST_OK);
}
