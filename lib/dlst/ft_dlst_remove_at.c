/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_remove_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:06:02 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 19:58:01 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_remove_at(t_dlst *list, size_t index, void **out)
{
	t_dnode		*node;
	t_dlst_stat	status;

	status = get_node_at(list, index, &node);
	if (status != LST_OK)
		return (status);
	if (out)
		*out = node->data;
	unlink(list, node);
	return (LST_OK);
}
