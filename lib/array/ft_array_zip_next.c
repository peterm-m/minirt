/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_zip_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:08:25 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

t_arr_stat	ft_array_zip_next(t_array_zip *iter, void **out1, void **out2)
{
	if (iter->index >= iter->ar1->size || iter->index >= iter->ar2->size)
		return (ARR_ITER_END);
	*out1 = iter->ar1->buffer[iter->index];
	*out2 = iter->ar2->buffer[iter->index];
	iter->index++;
	iter->last_removed = false;
	return (ARR_OK);
}
