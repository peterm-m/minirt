/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_filter_mut.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:06:25 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 19:58:01 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_filter_mut(t_dlst *list, bool (*pred) (const void*))
{
	t_dnode	*curr;
	t_dnode	*next;

	if (ft_dlst_size(list) == 0)
		return (LST_ERR_OUT_OF_RANGE);
	curr = list->head;
	next = NULL;
	while (curr)
	{
		next = curr->next;
		if (!pred(curr->data))
			unlink(list, curr);
		curr = next;
	}
	return (LST_OK);
}
