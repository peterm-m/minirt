/* ************************************************************************** */
/*                                      */
/*                            :::     ::::::::   */
/*   expand_capacity.c                  :+:   :+:    :+:   */
/*                          +:+ +:+       +:+    */
/*   By: pedromar <pedromar@student.42.fr>      +#+  +:+       +#+    */
/*                        +#+#+#+#+#+   +#+     */
/*   Created: 2024/04/27 17:33:58 by pedromar        #+#  #+#          */
/*   Updated: 2024/04/27 19:30:37 by pedromar       ###   ########.fr    */
/*                                      */
/* ************************************************************************** */

#include "ft_array_intern.h"

t_arr_stat	expand_capacity(t_array *ar)
{
	void	**new_buff;
	size_t	new_capacity;

	if (ar->capacity == ((size_t) - 2))
		return (ARR_ERR_MAX_CAPACITY);
	new_capacity = (size_t)(ar->capacity * ar->exp_factor);
	if (new_capacity <= ar->capacity)
		ar->capacity = ((size_t) - 2);
	else
		ar->capacity = new_capacity;
	new_buff = ar->mem_alloc(new_capacity * sizeof(void *));
	if (!new_buff)
		return (ARR_ERR_ALLOC);
	memcpy(new_buff, ar->buffer, ar->size * sizeof(void *));
	ar->mem_free(ar->buffer);
	ar->buffer = new_buff;
	return (ARR_OK);
}
