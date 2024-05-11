/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_filter_mut.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 20:03:30 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

static void	ft_array_filter_mut_aux(t_array **ar, size_t index[4],
	bool (*pred)(const void *))
{
	while (index[2] != ((size_t) - 1))
	{
		if (!pred((*ar)->buffer[index[2]]))
		{
			index[0]++;
			index[2]--;
			continue ;
		}
		if (index[0] > 0)
		{
			if (index[1] > 0)
			{
				index[3] = index[1] * sizeof(void *);
				memmove(&((*ar)->buffer[index[2] + 1]),
					&((*ar)->buffer[index[2] + 1 + index[0]]),
					index[3]);
			}
			(*ar)->size -= index[0];
			index[0] = 0;
		}
		index[2]--;
		index[1]++;
	}
}

t_arr_stat	ft_array_filter_mut(t_array *ar, bool (*pred)(const void *))
{
	size_t	index[4];

	index[0] = 0;
	index[1] = 0;
	if (ar->size == 0)
		return (ARR_ERR_OUT_OF_RANGE);
	index[2] = ar->size - 1;
	ft_array_filter_mut_aux(&ar, index, pred);
	if (index[0] > 0)
	{
		index[3] = index[1] * sizeof(void *);
		memmove(&(ar->buffer[0]),
			&(ar->buffer[index[0]]),
			index[3]);
		ar->size -= index[0];
	}
	return (ARR_OK);
}
