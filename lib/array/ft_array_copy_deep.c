/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_copy_deep.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 20:08:38 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

static void	ft_array_copy_deep_aux(t_array *ar, t_array	*copy,
		void *(*cp)(void *))
{
	size_t	i;

	copy->exp_factor = ar->exp_factor;
	copy->size = ar->size;
	copy->capacity = ar->capacity;
	copy->mem_alloc = ar->mem_alloc;
	copy->mem_calloc = ar->mem_calloc;
	copy->mem_free = ar->mem_free;
	i = 0;
	while (i < copy->size)
	{
		copy->buffer[i] = cp(ar->buffer[i]);
		i++;
	}
}

t_arr_stat	ft_array_copy_deep(t_array *ar, void *(*cp)(void *), t_array **out)
{
	t_array	*copy;

	copy = ar->mem_alloc(sizeof(t_array));
	if (!copy)
		return (ARR_ERR_ALLOC);
	copy->buffer = ar->mem_calloc(ar->capacity, sizeof(void *));
	if (!copy->buffer)
	{
		ar->mem_free(copy);
		return (ARR_ERR_ALLOC);
	}
	ft_array_copy_deep_aux(ar, copy, cp);
	*out = copy;
	return (ARR_OK);
}
