/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_filter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 20:06:41 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

static void	ft_array_filter_aux(t_array	*filtered, t_array *ar,
	bool (*pred)(const void *))
{
	size_t	i;
	size_t	f;

	f = 0;
	filtered->exp_factor = ar->exp_factor;
	filtered->size = 0;
	filtered->capacity = ar->capacity;
	filtered->mem_alloc = ar->mem_alloc;
	filtered->mem_calloc = ar->mem_calloc;
	filtered->mem_free = ar->mem_free;
	i = 0;
	while (i < ar->size)
	{
		if (pred(ar->buffer[i]))
		{
			filtered->buffer[f++] = ar->buffer[i];
			filtered->size++;
		}
		i++;
	}
}

t_arr_stat	ft_array_filter(t_array *ar,
	bool (*pred)(const void *), t_array **out)
{
	t_array	*filtered;

	if (ar->size == 0)
		return (ARR_ERR_OUT_OF_RANGE);
	filtered = ar->mem_alloc(sizeof(t_array));
	if (!filtered)
		return (ARR_ERR_ALLOC);
	filtered->buffer = ar->mem_calloc(ar->capacity, sizeof(void *));
	if (!(filtered->buffer))
	{
		ar->mem_free(filtered);
		return (ARR_ERR_ALLOC);
	}
	ft_array_filter_aux(filtered, ar, pred);
	*out = filtered;
	return (ARR_OK);
}
