/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_zip_replace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:39:25 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

t_arr_stat	ft_array_zip_replace(t_array_zip *iter,
	void *e1, void *e2, void **out[2])
{
	if ((iter->index - 1) >= iter->ar1->size
		|| (iter->index - 1) >= iter->ar2->size)
		return (ARR_ERR_OUT_OF_RANGE);
	ft_array_replace_at(iter->ar1, e1, iter->index - 1, out[0]);
	ft_array_replace_at(iter->ar2, e2, iter->index - 1, out[1]);
	return (ARR_OK);
}
