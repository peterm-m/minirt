/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:07:35 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 21:29:46 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

static void	fuction_aux(t_dlst *list, t_dnode *left, t_dnode *right)
{
	size_t	i;
	t_dnode	*tmpl;
	t_dnode	*tmpr;

	i = 0;
	while (i < list->size / 2)
	{
		tmpl = left->next;
		tmpr = right->prev;
		swap(left, right);
		left = tmpl;
		right = tmpr;
		i++;
	}
}

void	ft_dlst_reverse(t_dlst *list)
{
	t_dnode	*head_old;
	t_dnode	*tail_old;
	t_dnode	*left;
	t_dnode	*right;

	if (list->size == 0 || list->size == 1)
		return ;
	head_old = list->head;
	tail_old = list->tail;
	left = list->head;
	right = list->tail;
	fuction_aux(list, left, right);
	list->head = tail_old;
	list->tail = head_old;
}
