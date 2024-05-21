/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splice_between.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:51:55 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 19:52:06 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

void	splice_between(t_dlst *l1, t_dlst *l2, t_dnode *left, t_dnode *right)
{
	if (!left)
	{
		l1->head->prev = l2->tail;
		l2->tail->next = l1->head;
		l1->head = l2->head;
	}
	else if (!right)
	{
		l1->tail->next = l2->head;
		l2->head->prev = l1->tail;
		l1->tail = l2->tail;
	}
	else
	{
		left->next = l2->head;
		l2->head->prev = left;
		right->prev = l2->tail;
		l2->tail->next = right;
	}
	l1->size += l2->size;
	l2->head = NULL;
	l2->tail = NULL;
	l2->size = 0;
}
