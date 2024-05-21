/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_get_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:02:19 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 20:04:53 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_get_last(t_dlst *list, void **out)
{
	if (list->size == 0)
		return (LST_ERR_VALUE_NOT_FOUND);
	*out = list->tail->data;
	return (LST_OK);
}
