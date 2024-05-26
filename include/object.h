/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:20:02 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/26 18:00:26 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include	"ft_vector.h"
# include	"ft_array.h"
# include	"minirt.h"
# include	"ray.h"

typedef enum e_shape_type
{
	sh_sphere,
	sh_box,
	sh_plane,
	sh_cylinder,
}	t_shape_type;

typedef union u_shape
{
	struct	s_sp	*sp;
	struct	s_bx	*bx;
	struct	s_pl	*pl;
	struct	s_cy	*cy;
}	t_shape;

/*
	SPHERE
*/
typedef struct	s_sp
{
	t_vec3	center;
	float	radius;
	t_vec4	color;
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
	t_vec3	center;
	t_vec3	half_side;
	t_vec4	color;
}	t_bx;

bool		interseccion_bx(t_ray *r, t_bx	*bx);
t_vec3		normal_bx(t_vec3 *p, t_bx *bx);
// texture_bx()

/*
	PLANE
*/
typedef struct s_pl
{
	t_vec3	point;
	t_vec3	normal;
	float	np;
	t_vec4	color;
}	t_pl;

bool	interseccion_pl(t_ray *r, t_pl	*pl);
// t_vec3	normal_pl(t_vec3 *p, t_pl *pl);
// texture_pl()

/*
	CYLINDER
*/
typedef struct s_cy
{
	t_vec3	center;
	t_vec3	normal;
	float	radius;
	float	height;
	t_vec4	color;
}	t_cy;

bool	interseccion_cy(t_ray *r, t_cy	*cy);
t_vec3	normal_cy(t_vec3 *p, t_cy *cy);
// texture_cy()

/*
 TODO

typedef	struct	s_el
{
	t_vec3	center;
	t_vec4	color;
}	t_el;

int	interseccion_el(t_ray *r, t_el	*el);

typedef	struct	s_hb
{
	t_vec3	center;
	t_vec4	color;
}	t_hb;

int	interseccion_hb(t_ray *r, t_hb	*hb);

typedef	struct	s_pb
{
	t_vec3	center;
	t_vec4	color;
}	t_pb;

int	interseccion_pb(t_ray *r, t_pb	*pb);

typedef	struct	s_cn
{
	t_vec3	center;
	t_vec3	normal;
	folat	height_min;
	folat	height_max;
	t_vec4	color;
}	t_cn;

int	interseccion_cn(t_ray *r, t_cn	*cn);

typedef struct	s_curve_dots;
{
	size_t		n_point;
	t_point		*points;
}	t_curve_dots;
*/

typedef struct s_object
{
	t_shape_type	type;
	t_shape			shape;
	t_vec3			pos_obj;
	t_vec3			rot_obj;
	t_vec3			scale_obj;
	t_matrix4		local_world;
	t_matrix4		world_local;
}	t_object;

/*
 *	create new object with n points
*/
t_object	*object_new(t_shape_type type);

/*
 *	destroy object obj
*/
void		object_destroy(t_object *obj);

/*
 *	ubdate position, orientation and scale object obj
 *		Inverse transformation:
 *		inv_Scale * inv_Trasn * inv_RotZ * inv_RotY * inv_RotX
*/
void		update_object(t_object *obj);

#endif