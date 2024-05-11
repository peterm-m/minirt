/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_conf_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 18:58:37 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

void	ft_array_conf_init(t_array_conf *conf)
{
	conf->exp_factor = DEFAULT_EXPANSION_FACTOR;
	conf->capacity = DEFAULT_CAPACITY;
	conf->mem_alloc = malloc;
	conf->mem_calloc = calloc;
	conf->mem_free = free;
}
