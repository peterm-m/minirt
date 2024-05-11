/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_new_conf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:14:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/27 19:51:24 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_intern.h"

static t_arr_stat	checks_new_conf(t_array_conf const *const conf,
	float *ex, t_array **ar)
{
	if (conf->exp_factor <= 1)
		*ex = DEFAULT_EXPANSION_FACTOR;
	else
		*ex = conf->exp_factor;
	if (!conf->capacity || *ex >= ((size_t)-2) / conf->capacity)
		return (ARR_ERR_INVALID_CAPACITY);
	*ar = conf->mem_calloc(1, sizeof(t_array));
	if (!(*ar))
		return (ARR_ERR_ALLOC);
	return (ARR_OK);
}

t_arr_stat	ft_array_new_conf(t_array_conf const *const conf, t_array **out)
{
	t_arr_stat	status;
	t_array		*ar;
	float		ex;
	void		**buff;

	status = checks_new_conf(conf, &ex, &ar);
	if (status != ARR_OK)
		return (status);
	buff = conf->mem_alloc(conf->capacity * sizeof(void *));
	if (!buff)
	{
		conf->mem_free(ar);
		return (ARR_ERR_ALLOC);
	}
	ar->buffer = buff;
	ar->exp_factor = ex;
	ar->capacity = conf->capacity;
	ar->mem_alloc = conf->mem_alloc;
	ar->mem_calloc = conf->mem_calloc;
	ar->mem_free = conf->mem_free;
	*out = ar;
	return (ARR_OK);
}
