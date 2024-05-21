/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_remove_all_cb.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:25:25 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 19:58:01 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_remove_all_cb(t_dlst *list, void (*cb) (void*))
{
	bool	unlinked;

	unlinked = unlink_all(list, cb);
	if (unlinked)
	{
		list->head = NULL;
		list->tail = NULL;
		return (LST_OK);
	}
	return (LST_ERR_VALUE_NOT_FOUND);
}
