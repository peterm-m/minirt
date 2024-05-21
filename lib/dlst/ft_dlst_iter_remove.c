/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_iter_remove.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:10:17 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 19:58:01 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_iter_remove(t_dlst_iter *iter, void **out)
{
	void	*e;

	if (!iter->last)
		return (LST_ERR_VALUE_NOT_FOUND);
	e = unlink(iter->list, iter->last);
	iter->last = NULL;
	if (out)
		*out = e;
	return (LST_OK);
}
