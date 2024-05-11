/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_trim_capacity.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:38:15 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

t_arr_stat	ft_array_trim_capacity(t_array *ar)
{
	void	**new_buff;
	size_t	size;

	if (ar->size == ar->capacity)
		return (ARR_OK);
	new_buff = ar->mem_calloc(ar->size, sizeof(void *));
	if (!new_buff)
		return (ARR_ERR_ALLOC);
	size = (ar->size < 1) * 1 + (ar->size >= 1) * ar->size;
	memcpy(new_buff, ar->buffer, size * sizeof(void *));
	ar->mem_free(ar->buffer);
	ar->buffer = new_buff;
	ar->capacity = ar->size;
	return (ARR_OK);
}
