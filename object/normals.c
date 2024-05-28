/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:04:05 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/28 14:14:48 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	normal_sp(t_vec3 *p, t_sp *sp)
{
	t_vec3	v;

	v = ft_subv3(*p, sp->center);
	return (ft_divv3f(v, ft_lenv3(v)));
}

t_vec3	normal_pl(t_vec3 *p, t_pl *pl)
{
	(void)p;
	return (pl->normal);
}

t_vec3	normal_cy(t_vec3 *p, t_cy *cy)
{
	t_vec3	v;
	float	l;

	v = ft_subv3(*p, cy->center);
	l = ft_dotv3(v, cy->normal);
	if (l >= cy->height || l <= 0.0f)
		return (ft_mulv3f(cy->normal, ((l >= cy->height) - (l <= 0.0f))));
	return (ft_normv3(ft_subv3(v, ft_mulv3f(cy->normal, l))));
}

// TODO
t_vec3	normal_bx(t_vec3 *p, t_bx *bx)
{
	(void)p;
	(void)bx;
	return (ft_vec3(0.0f, 0.0f, 0.0f));
}
