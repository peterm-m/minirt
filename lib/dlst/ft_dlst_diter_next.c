/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_diter_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:59:10 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 21:27:38 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_diter_next(t_dlst_iter *iter, void **out)
{
	void	*data;

	if (!iter->next)
		return (LST_ITER_END);
	data = iter->next->data;
	iter->last = iter->next;
	iter->next = iter->next->prev;
	iter->index--;
	*out = data;
	return (LST_OK);
}
