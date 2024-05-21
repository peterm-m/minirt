/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_contains.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:07:17 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 20:08:47 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

size_t	ft_dlst_contains(t_dlst *list, void *element)
{
	t_dnode	*node;
	size_t	e_count;

	e_count = 0;
	node = list->head;
	while (node)
	{
		if (node->data == element)
			e_count++;
		node = node->next;
	}
	return (e_count);
}
