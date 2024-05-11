/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_contains_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:36:40 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

size_t	ft_array_contains_value(t_array *ar, void *element,
	int (*cmp)(const void *, const void *))
{
	size_t	o;
	size_t	i;

	o = 0;
	i = 0;
	while (i < ar->size)
	{
		if (cmp(element, ar->buffer[i++]) == 0)
			o++;
	}
	return (o);
}
