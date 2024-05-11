/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_iter_remove.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:07:42 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

t_arr_stat	ft_array_iter_remove(t_array_iter *iter, void **out)
{
	t_arr_stat	status;

	status = ARR_ERR_VALUE_NOT_FOUND;
	if (!iter->last_removed)
	{
		status = ft_array_remove_at(iter->ar, iter->index - 1, out);
		if (status == ARR_OK)
			iter->last_removed = true;
	}
	return (status);
}
