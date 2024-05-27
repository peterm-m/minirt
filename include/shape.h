/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:04:37 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/27 17:01:50 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "ft_vector.h"
# include "material.h"
# include "minirt.h"
# include "ray.h"

typedef enum e_shape_type
{
	sh_sphere,
	sh_box,
	sh_plane,
	sh_cylinder,
}	t_shape_type;

typedef union u_shape
{
	struct s_sp	*sp;
	struct s_bx	*bx;
	struct s_pl	*pl;
	struct s_cy	*cy;
}	t_shape;

/*
	SPHERE
*/
typedef struct s_sp
{
	t_vec3		center;
	float		radius;
	t_material	material;
}	t_sp;
// CHECK: best option save radius * radius??

bool	interseccion_sp(t_ray *r, t_sp	*sp);
t_vec3	normal_sp(t_vec3 *p, t_sp *sp);
t_vec2	texture_sp(t_vec3 *p, t_sp *sp);

/*
	BOX
*/
typedef struct s_bx
{
	t_vec3		center;
	t_vec3		half_side;
	t_material	material;
}	t_bx;

bool	interseccion_bx(t_ray *r, t_bx	*bx);
t_vec3	normal_bx(t_vec3 *p, t_bx *bx);
t_vec2	texture_bx(t_vec3 *p, t_bx *bx);

/*
	PLANE
*/
typedef struct s_pl
{
	t_vec3		point;
	t_vec3		normal;
	float		np;
	t_material	material;
}	t_pl;

bool	interseccion_pl(t_ray *r, t_pl	*pl);
t_vec3	normal_pl(t_vec3 *p, t_pl *pl);
t_vec2	texture_pl(t_vec3 *p, t_pl *pl);

/*
	CYLINDER
*/
typedef struct s_cy
{
	t_vec3		center;
	t_vec3		normal;
	float		radius;
	float		height;
	t_material	material;
}	t_cy;

bool	interseccion_cy(t_ray *r, t_cy	*cy);
t_vec3	normal_cy(t_vec3 *p, t_cy *cy);
t_vec2	texture_cy(t_vec3 *p, t_cy *cy);

/*
 TODO other shapes
*/
// hiperboloid
typedef struct s_hb			t_hb;
// paraboloid
typedef struct s_pb			t_pb;
// cone
typedef struct s_cn			t_cn;
// dots
typedef struct s_curve_dots	t_curve_dots;
// other

#endif