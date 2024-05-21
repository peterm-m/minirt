/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:48:21 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/07 16:24:31 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

static int	swap_aux(t_dnode *n1, t_dnode *n2)
{
	if (n1->next == n2 || n2->next == n1)
	{
		swap_adjacent(n1, n2);
		return (1);
	}
	return (0);
}

void	swap(t_dnode *n1, t_dnode *n2)
{
	t_dnode	*n1_left;
	t_dnode	*n1_right;
	t_dnode	*n2_left;
	t_dnode	*n2_right;

	if (swap_aux(n1, n2))
		return ;
	n1_left = n1->prev;
	n1_right = n1->next;
	n2_left = n2->prev;
	n2_right = n2->next;
	if (n1_left)
		n1_left->next = n2;
	n2->prev = n1_left;
	if (n1_right)
		n1_right->prev = n2;
	n2->next = n1_right;
	if (n2_left)
		n2_left->next = n1;
	n1->prev = n2_left;
	if (n2_right)
		n2_right->prev = n1;
	n1->next = n2_right;
}
