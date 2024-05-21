/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_after.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:38:59 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 19:48:02 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

void	link_after(t_dnode *base, t_dnode *ins)
{
	if (ins->next)
		ins->next->prev = ins->prev;
	if (ins->prev)
		ins->prev->next = ins->next;
	if (!base->next)
	{
		ins->prev = base;
		base->next = ins;
		ins->next = NULL;
	}
	else
	{
		ins->next = base->next;
		ins->next->prev = ins;
		ins->prev = base;
		base->next = ins;
	}
}
