/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:00:07 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

void	ft_array_destroy(t_array *ar)
{
	ar->mem_free(ar->buffer);
	ar->mem_free(ar);
}
