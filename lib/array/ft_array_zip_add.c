/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_zip_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:08:49 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

t_arr_stat	ft_array_zip_add(t_array_zip *iter, void *e1, void *e2)
{
	size_t		index;
	t_array		*ar1;
	t_array		*ar2;
	t_arr_stat	status;

	index = iter->index++;
	ar1 = iter->ar1;
	ar2 = iter->ar2;
	if (ar1->size == ar1->capacity)
	{
		status = expand_capacity(ar1);
		if (status != ARR_OK)
			return (ARR_ERR_ALLOC);
	}
	if (ar2->size == ar2->capacity)
	{
		status = expand_capacity(ar2);
		if (status != ARR_OK)
			return (ARR_ERR_ALLOC);
	}
	ft_array_add_at(ar1, e1, index);
	ft_array_add_at(ar2, e2, index);
	return (ARR_OK);
}
