/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:00:48 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 20:01:35 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_sort(t_dlst *list,
	int (*cmp)(void const *e1, void const *e2))
{
	void		**elements;
	t_dnode		*node;
	size_t		i;
	t_dlst_stat	status;

	status = ft_dlst_to_array(list, &elements);
	if (status != LST_OK)
		return (status);
	node = list->head;
	qsort(elements, list->size, sizeof(void *), cmp);
	i = 0;
	while (i < list->size)
	{
		node->data = elements[i++];
		node = node->next;
	}
	list->mem_free(elements);
	return (LST_OK);
}
