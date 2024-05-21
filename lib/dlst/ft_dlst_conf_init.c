/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_conf_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:24:51 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 19:24:54 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

void	ft_dlst_conf_init(t_dlst_conf *conf)
{
	conf->mem_alloc = malloc;
	conf->mem_calloc = calloc;
	conf->mem_free = free;
}
