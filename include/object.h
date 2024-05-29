/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:20:02 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/29 15:40:23 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "ft_vector.h"
# include "shape.h"
# include "minirt.h" 

typedef struct s_object
{
	t_shape_type	type;
	t_shape			shape;
	t_material		material;
	t_vec3			pos_obj;
	t_vec3			rot_obj;
	t_vec3			scale_obj;
	t_matrix4		local_world;
	t_matrix4		world_local;
}	t_object;

/*
 *	create new object with n points
*/
t_object	*object_new(t_shape_type type, t_shape shape);

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