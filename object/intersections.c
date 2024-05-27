/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:13:56 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/27 16:34:03 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ray.h"

/*
 * MANDATORY
*/

bool	interseccion_sp(t_ray *r, t_sp	*sp)
{
	t_vec3	m;
	float	b;
	float	c;
	float	discriminant;

	m = ft_subv3(r->o, sp->center);
	b = ft_dotv3(m, r->d);
	c = ft_lensqrv3(m) - sp->radius * sp->radius;
	if (c > 0.0f && b > 0.0f)
		return (false);
	discriminant = b * b - c;
	if (discriminant < 0.0f)
		return (false);
	r->t = -b - sqrt(discriminant);
	return (true);
}

bool	interseccion_pl(t_ray *r, t_pl	*pl)
{
	float	nd;
	float	no;

	nd = ft_dotv3(r->d, pl->normal);
	if (nd < 1e-6)
		return (false);
	no = ft_dotv3(r->o, pl->normal);
	r->t = MAX(pl->np - no / nd, 0.0f);
	return (r->t > 0.0f);
}

/*
 * ec_coef[4]: coefficient and discriminat ec 2nd order
 *			A * t^2 + B * t + C = 0 
 *		ec_coef[0]: A
 *		ec_coef[1]: B
 *		ec_coef[2]: C
 *		ec_coef[3]: discriminant = A * A - B * C
 * nr[2]: projection ray in cylinder normal ray(t) = o + t * d
 * 		nr[0] = cy_normal * d
 * 		nr[1] = cy_normal * o
*/

bool	interseccion_cy(t_ray *r, t_cy *cy)
{
	t_vec3	oc;
	float	nr[2];
	float	ec_coef[4];
	float	y;

	oc = ft_subv3(r->o, cy->center);
	nr[0] = ft_dotv3(cy->normal, r->d);
	nr[1] = ft_dotv3(cy->normal, oc);
	ec_coef[0] = 1.0f - nr[0] * nr[0] * cy->height;
	ec_coef[1] = ft_dotv3(oc, r->d) - nr[1] * nr[0] * cy->height;
	ec_coef[2] = ft_dotv3(oc, oc) - nr[1] * nr[1] * cy->height \
			- cy->radius * cy->radius;
	ec_coef[3] = ec_coef[1] * ec_coef[1] - ec_coef[0] * ec_coef[2];
	if (ec_coef[3] < 0.0f)
		return (false);
	ec_coef[3] = sqrt(ec_coef[3]);
	r->t = (-ec_coef[1] - ec_coef[3]) / ec_coef[0];
	y = nr[1] + r->t * nr[0];
	if (y > 0.0 && y < cy->height)
		return (true);
	r->t = (((y > 0.0) * cy->height) - nr[1]) / nr[0];
	if (fabsf(ec_coef[1] + ec_coef[0] * r->t) < ec_coef[3])
		return (true);
	r->t = 0.0f;
	return (false);
}

/*
 * EXTRA
*/

bool	interseccion_bx(t_ray *r, t_bx *bx)
{
	t_vec3	aux;
	t_vec3	t0;
	t_vec3	t1;

	aux = ft_vec3(1.0f / r->d.x, 1.0f / r->d.y, 1.0f / r->d.z);
	t0 = ft_mulv3v(ft_subv3(ft_addv3(bx->center, bx->half_side), r->o), aux);
	t1 = ft_mulv3v(ft_subv3(ft_subv3(bx->center, bx->half_side), r->o), aux);
	aux.x = MIN(t0.x, t1.x);
	aux.y = MAX(t0.x, t1.x);
	aux.x = MAX(aux.x, MIN(t0.y, t1.y));
	aux.y = MIN(aux.y, MAX(t0.y, t1.y));
	aux.x = MAX(aux.x, MIN(t0.z, t1.z));
	aux.y = MIN(aux.y, MAX(t0.z, t1.z));
	return (aux.y > MAX(aux.x, 0.0f));
}
