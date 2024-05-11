/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_replace_at.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:01:07 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

t_arr_stat	ft_array_replace_at(t_array *ar,
		void *element, size_t index, void **out)
{
	if (index >= ar->size)
		return (ARR_ERR_OUT_OF_RANGE);
	if (out)
		*out = ar->buffer[index];
	ar->buffer[index] = element;
	return (ARR_OK);
}
