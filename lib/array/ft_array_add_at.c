/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_add_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:00:50 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

t_arr_stat	ft_array_add_at(t_array *ar, void *element, size_t index)
{
	t_arr_stat	status;
	size_t		shift;

	if (index == ar->size)
		return (ft_array_add(ar, element));
	if ((ar->size == 0 && index != 0) || index > (ar->size - 1))
		return (ARR_ERR_OUT_OF_RANGE);
	if (ar->size >= ar->capacity)
	{
		status = expand_capacity(ar);
		if (status != ARR_OK)
			return (status);
	}
	shift = (ar->size - index) * sizeof(void *);
	memmove(&(ar->buffer[index + 1]),
		&(ar->buffer[index]),
		shift);
	ar->buffer[index] = element;
	ar->size++;
	return (ARR_OK);
}
