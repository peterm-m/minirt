/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:05:24 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

void	ft_array_reverse(t_array *ar)
{
	size_t	i;
	size_t	j;
	void	*tmp;

	if (ar->size == 0)
		return ;
	i = 0;
	j = ar->size - 1;
	while (i < ar->size / 2)
	{
		tmp = ar->buffer[i];
		ar->buffer[i++] = ar->buffer[j];
		ar->buffer[j--] = tmp;
	}
}
