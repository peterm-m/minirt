/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:38:51 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 20:57:16 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_to_array(t_dlst *list, void ***out)
{
	void	**array;
	t_dnode	*node;
	size_t	i;

	if (list->size == 0)
		return (LST_ERR_INVALID_RANGE);
	array = list->mem_calloc(list->size, sizeof(void *));
	if (!array)
		return (LST_ERR_ALLOC);
	node = list->head;
	i = 0;
	while (i < list->size)
	{
		array[i++] = node->data;
		node = node->next;
	}
	*out = array;
	return (LST_OK);
}
