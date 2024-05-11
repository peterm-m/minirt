/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_zip_remove.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:08:36 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

t_arr_stat	ft_array_zip_remove(t_array_zip *iter, void **out1, void **out2)
{
	if ((iter->index - 1) >= iter->ar1->size
		|| (iter->index - 1) >= iter->ar2->size)
		return (ARR_ERR_OUT_OF_RANGE);
	if (!iter->last_removed)
	{
		ft_array_remove_at(iter->ar1, iter->index - 1, out1);
		ft_array_remove_at(iter->ar2, iter->index - 1, out2);
		iter->last_removed = true;
		return (ARR_OK);
	}
	return (ARR_ERR_VALUE_NOT_FOUND);
}
