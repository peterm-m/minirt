/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:05:49 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 20:08:53 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

void	ft_dlst_foreach(t_dlst *list, void (*op) (void *e))
{
	t_dnode	*n;

	n = list->head;
	while (n)
	{
		op(n->data);
		n = n->next;
	}
}
