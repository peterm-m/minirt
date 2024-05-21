/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_adjacent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:50:27 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 19:55:12 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

void	swap_adjacent(t_dnode *n1, t_dnode *n2)
{
	if (n1->next == n2)
	{
		if (n2->next)
			n2->next->prev = n1;
		n1->next = n2->next;
		if (n1->prev)
			n1->prev->next = n2;
		n2->prev = n1->prev;
		n1->prev = n2;
		n2->next = n1;
		return ;
	}
	if (n2->next == n1)
	{
		if (n1->next)
			n1->next->prev = n2;
		n2->next = n1->next;
		if (n2->prev)
			n2->prev->next = n1;
		n1->prev = n2->prev;
		n2->prev = n1;
		n1->next = n2;
		return ;
	}
}
