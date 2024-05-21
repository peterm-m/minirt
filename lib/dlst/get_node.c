/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:51:48 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 19:51:52 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dnode	*get_node(t_dlst *list, void *element)
{
	t_dnode	*node;

	node = list->head;
	while (node)
	{
		if (node->data == element)
			return (node);
		node = node->next;
	}
	return (NULL);
}
