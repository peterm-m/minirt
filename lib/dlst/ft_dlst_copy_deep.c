/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_copy_deep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:14:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/07 16:21:00 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

static t_dlst_stat	ft_dlst_copy_deep_loop(t_dlst *list, t_dlst *copy,
				void *(*cp) (void *e1))
{
	t_dlst_stat	status;
	t_dnode		*node;

	node = list->head;
	while (node)
	{
		status = ft_dlst_add(copy, cp(node->data));
		if (status != LST_OK)
		{
			ft_dlst_destroy(copy);
			return (status);
		}
		node = node->next;
	}
	return (status);
}

t_dlst_stat	ft_dlst_copy_deep(t_dlst *list,
	void *(*cp) (void *e1), t_dlst **out)
{
	t_dlst_conf	conf;
	t_dlst		*copy;
	t_dlst_stat	status;

	conf.mem_alloc = list->mem_alloc;
	conf.mem_calloc = list->mem_calloc;
	conf.mem_free = list->mem_free;
	status = ft_dlst_new_conf(&conf, &copy);
	if (status != LST_OK)
		return (status);
	if (!list->head)
	{
		*out = copy;
		return (LST_OK);
	}
	status = ft_dlst_copy_deep_loop(list, copy, cp);
	if (status != LST_OK)
		return (status);
	else
		*out = copy;
	return (LST_OK);
}
