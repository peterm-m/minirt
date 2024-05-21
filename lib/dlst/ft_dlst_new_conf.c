/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new_conf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:04:53 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 21:05:21 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_new_conf(t_dlst_conf const *const conf, t_dlst **out)
{
	t_dlst	*list;

	list = conf->mem_calloc(1, sizeof(t_dlst));
	if (!list)
		return (LST_ERR_ALLOC);
	list->mem_alloc = conf->mem_alloc;
	list->mem_calloc = conf->mem_calloc;
	list->mem_free = conf->mem_free;
	*out = list;
	return (LST_OK);
}
