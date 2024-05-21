/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_remove_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:20:48 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 19:58:01 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_remove_all(t_dlst *list)
{
	bool	unlinked;

	unlinked = unlink_all(list, NULL);
	if (unlinked)
	{
		list->head = NULL;
		list->tail = NULL;
		return (LST_OK);
	}
	return (LST_ERR_VALUE_NOT_FOUND);
}
