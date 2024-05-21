/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:51:11 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 20:08:08 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

bool	unlink_all(t_dlst *list, void (*cb) (void*))
{
	t_dnode	*node;
	t_dnode	*tmp;

	if (list->size == 0)
		return (false);
	node = list->head;
	while (node)
	{
		tmp = node->next;
		if (cb)
			cb(node->data);
		unlink(list, node);
		node = tmp;
	}
	return (true);
}
