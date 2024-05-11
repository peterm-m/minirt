/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_remove_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:02:05 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

t_arr_stat	ft_array_remove_at(t_array *ar, size_t index, void **out)
{
	size_t	block_size;

	if (index >= ar->size)
		return (ARR_ERR_OUT_OF_RANGE);
	if (out)
		*out = ar->buffer[index];
	if (index != ar->size - 1)
	{
		block_size = (ar->size - 1 - index) * sizeof(void *);
		memmove(&(ar->buffer[index]),
			&(ar->buffer[index + 1]),
			block_size);
	}
	ar->size--;
	return (ARR_OK);
}
