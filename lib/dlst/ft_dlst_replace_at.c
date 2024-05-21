/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_replace_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:07:08 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 21:07:21 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_replace_at(t_dlst *list, void *element,
	size_t index, void **out)
{
	t_dnode		*node;
	t_dlst_stat	status;
	void		*old;

	status = get_node_at(list, index, &node);
	if (status == LST_OK)
	{
		old = node->data;
		node->data = element;
		if (out)
			*out = old;
	}
	return (status);
}
