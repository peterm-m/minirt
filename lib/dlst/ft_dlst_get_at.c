/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_get_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:05:24 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 20:08:55 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_get_at(t_dlst *list, size_t index, void **out)
{
	t_dnode		*node;
	t_dlst_stat	status;

	status = get_node_at(list, index, &node);
	if (status == LST_OK)
		*out = node->data;
	return (status);
}
