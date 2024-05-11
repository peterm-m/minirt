/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_reduce.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:36:53 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

void	ft_array_reduce(t_array *ar,
	void (*fn)(void *, void *, void *), void *result)
{
	size_t	i;

	if (ar->size == 1)
	{
		fn(ar->buffer[0], NULL, result);
		return ;
	}
	if (ar->size > 1)
		fn(ar->buffer[0], ar->buffer[1], result);
	i = 2;
	while (i < ar->size)
		fn(result, ar->buffer[i++], result);
}
