/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_iter_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:11:07 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 21:11:23 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

void	ft_dlst_iter_init(t_dlst_iter *iter, t_dlst *list)
{
	iter->index = 0;
	iter->list = list;
	iter->last = NULL;
	iter->next = list->head;
}
