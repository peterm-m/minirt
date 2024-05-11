/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_subarray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:04:01 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

t_arr_stat	ft_array_subarray(t_array *ar, size_t b, size_t e, t_array **out)
{
	t_array	*sub_ar;

	if (b > e || e >= ar->size)
		return (ARR_ERR_INVALID_RANGE);
	sub_ar = ar->mem_calloc(1, sizeof(t_array));
	if (!sub_ar)
		return (ARR_ERR_ALLOC);
	sub_ar->buffer = ar->mem_alloc(ar->capacity * sizeof(void *));
	if (!sub_ar->buffer)
	{
		ar->mem_free(sub_ar);
		return (ARR_ERR_ALLOC);
	}
	sub_ar->mem_alloc = ar->mem_alloc;
	sub_ar->mem_calloc = ar->mem_calloc;
	sub_ar->mem_free = ar->mem_free;
	sub_ar->size = e - b + 1;
	sub_ar->capacity = sub_ar->size;
	memcpy(sub_ar->buffer,
		&(ar->buffer[b]),
		sub_ar->size * sizeof(void *));
	*out = sub_ar;
	return (ARR_OK);
}
