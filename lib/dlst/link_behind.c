/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_behind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:37:51 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 19:38:48 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

void	link_behind(t_dnode *const base, t_dnode *ins)
{
	if (ins->next != NULL)
		ins->next->prev = ins->prev;
	if (ins->prev != NULL)
		ins->prev->next = ins->next;
	if (base->prev == NULL)
	{
		ins->prev = NULL;
		ins->next = base;
		base->prev = ins;
	}
	else
	{
		ins->prev = base->prev;
		ins->prev->next = ins;
		ins->next = base;
		base->prev = ins;
	}
}
