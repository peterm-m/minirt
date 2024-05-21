/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:23:00 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/07 15:51:57 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_remove(t_dlst *list, void *element, void **out)
{
	t_dnode	*node;

	node = get_node(list, element);
	if (!node)
		return (LST_ERR_VALUE_NOT_FOUND);
	if (out)
		*out = node->data;
	unlink(list, node);
	return (LST_OK);
}
