/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:01:51 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

t_arr_stat	ft_array_remove(t_array *ar, void *element, void **out)
{
	size_t		index;
	size_t		block_size;
	t_arr_stat	status;

	status = ft_array_index_of(ar, element, &index);
	if (status == ARR_ERR_OUT_OF_RANGE)
		return (ARR_ERR_VALUE_NOT_FOUND);
	if (index != ar->size - 1)
	{
		block_size = (ar->size - 1 - index) * sizeof(void *);
		memmove(&(ar->buffer[index]),
			&(ar->buffer[index + 1]),
			block_size);
	}
	ar->size--;
	if (out)
		*out = element;
	return (ARR_OK);
}
