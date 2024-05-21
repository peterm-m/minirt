/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_filter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:00:49 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 21:27:07 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_filter(t_dlst *list, bool (*pred)(const void*),
	t_dlst **out)
{
	t_dlst	*filtered;
	t_dnode	*curr;

	if (ft_dlst_size(list) == 0)
		return (LST_ERR_OUT_OF_RANGE);
	filtered = NULL;
	ft_dlst_new(&filtered);
	if (!filtered)
		return (LST_ERR_ALLOC);
	curr = list->head;
	while (curr)
	{
		if (pred(curr->data))
		{
			ft_dlst_add(filtered, curr->data);
		}
		curr = curr->next;
	}
	*out = filtered;
	return (LST_OK);
}
