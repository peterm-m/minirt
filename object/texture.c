/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:05:23 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/27 16:27:12 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec2	texture_sp(t_vec3 *p, t_sp *sp)
{
	t_vec2	t;

	t.x = (1.0f + atan2(p->z, p->x) / M_PI) * 0.5f;
	t.y = acosf(p->y) / M_PI;
	return (t);
}

t_vec2	texture_pl(t_vec3 *p, t_pl *pl)
{
	t_vec2	t;

	t.x = p->x;
	t.y = p->y;
	return (t);
}

t_vec2	texture_cy(t_vec3 *p, t_cy *cy)
{
	t_vec2	t;

	t.x = ft_dotv3(ft_subv3(*p, cy->center), cy->normal);
	t.y = atan2(p->y, p->x);
	t.y += (t.y < 0.0f) * 2.0f * M_PI;
	return (t);
}

// TODO
t_vec2	texture_bx(t_vec3 *p, t_bx *bx)
{
	(void)p;
	(void)bx;
	return (ft_vec2(0.0f, 0.0f));
}
