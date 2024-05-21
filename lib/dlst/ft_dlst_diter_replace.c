/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_diter_replace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:00:09 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 21:00:12 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_diter_replace(t_dlst_iter *iter, void *element, void **out)
{
	void	*old;

	if (!iter->last)
		return (LST_ERR_VALUE_NOT_FOUND);
	old = iter->last->data;
	iter->last->data = element;
	if (out)
		*out = old;
	return (LST_OK);
}
