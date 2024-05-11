/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_index_of.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:14:24 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

t_arr_stat	ft_array_index_of(t_array *ar, void *element, size_t *index)
{
	size_t	i;

	i = 0;
	while (i < ar->size)
	{
		if (ar->buffer[i] == element)
		{
			*index = i;
			return (ARR_OK);
		}
		i++;
	}
	return (ARR_ERR_OUT_OF_RANGE);
}
