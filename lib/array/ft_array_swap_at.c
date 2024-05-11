/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_swap_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:01:24 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

t_arr_stat	ft_array_swap_at(t_array *ar, size_t index1, size_t index2)
{
	void	*tmp;

	if (index1 >= ar->size || index2 >= ar->size)
		return (ARR_ERR_OUT_OF_RANGE);
	tmp = ar->buffer[index1];
	ar->buffer[index1] = ar->buffer[index2];
	ar->buffer[index2] = tmp;
	return (ARR_OK);
}
