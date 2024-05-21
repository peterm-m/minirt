/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_iter_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:10:42 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 21:11:02 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_iter_next(t_dlst_iter *iter, void **out)
{
	void	*data;

	if (!iter->next)
		return (LST_ITER_END);
	data = iter->next->data;
	iter->last = iter->next;
	iter->next = iter->next->next;
	iter->index++;
	*out = data;
	return (LST_OK);
}
