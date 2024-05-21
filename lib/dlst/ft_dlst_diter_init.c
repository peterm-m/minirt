/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_diter_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:58:50 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 21:27:35 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

void	ft_dlst_diter_init(t_dlst_iter *iter, t_dlst *list)
{
	iter->index = list->size;
	iter->list = list;
	iter->last = NULL;
	iter->next = list->tail;
}
