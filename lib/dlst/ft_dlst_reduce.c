/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_reduce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:07:54 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/07 17:00:28 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_reduce(t_dlst *list,
	void (*fn)(void *, void *, void *), void *result)
{
	t_dnode	*curr;
	t_dnode	*next;
	size_t	list_size;

	list_size = ft_dlst_size(list);
	if (list_size == 0)
		return (LST_ERR_OUT_OF_RANGE);
	if (list_size == 1)
	{
		fn(list->head->data, NULL, result);
		return (LST_OK);
	}
	fn(list->head->data, list->head->next->data, result);
	curr = list->head->next->next;
	next = NULL;
	while (curr)
	{
		next = curr->next;
		fn(result, curr->data, result);
		curr = next;
	}
	return (LST_OK);
}
