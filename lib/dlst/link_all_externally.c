/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_all_externally.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:52:11 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/07 16:40:22 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

static bool	link_all_externally_aux(t_dnode *new, t_dlst *list, t_dnode **h)
{
	t_dnode	*tmp;

	if (!new)
	{
		while (*h)
		{
			tmp = (*h)->next;
			list->mem_free(*h);
			*h = tmp;
		}
		return (false);
	}
	return (true);
}

static void	link_all_externally_aux1(t_dnode *new, t_dnode **h, t_dnode **t)
{
	if (!*h)
	{
		*h = new;
		*t = new;
	}
	else
	{
		(*t)->next = new;
		new->prev = *t;
		*t = new;
	}
}

bool	link_all_externally(t_dlst *list, t_dnode **h, t_dnode **t)
{
	t_dnode	*new;
	t_dnode	*insert;
	size_t	i;

	insert = list->head;
	i = 0;
	while (i++ < list->size)
	{
		new = list->mem_calloc(1, sizeof(t_dnode));
		if (!link_all_externally_aux(new, list, h))
			return (false);
		new->data = insert->data;
		link_all_externally_aux1(new, h, t);
		insert = insert->next;
	}
	return (true);
}
