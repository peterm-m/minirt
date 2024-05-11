/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:35:53 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

t_arr_stat	ft_array_add(t_array *ar, void *element)
{
	t_arr_stat	status;

	if (ar->size >= ar->capacity)
	{
		status = expand_capacity(ar);
		if (status != ARR_OK)
			return (status);
	}
	ar->buffer[ar->size] = element;
	ar->size++;
	return (ARR_OK);
}
