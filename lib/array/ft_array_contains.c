/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_contains.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:05:54 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

size_t	ft_array_contains(t_array *ar, void *element)
{
	size_t	o;
	size_t	i;

	o = 0;
	i = 0;
	while (i < ar->size)
	{
		if (ar->buffer[i++] == element)
			o++;
	}
	return (o);
}
