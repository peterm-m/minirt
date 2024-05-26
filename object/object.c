/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:19:20 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/25 20:04:19 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*object_new(t_shape_type type)
{
	t_object	*obj;

	obj = mallox(sizeof(t_object));
	obj->pos_obj = ft_vec3(0.0f, 0.0f, 0.0f);
	obj->rot_obj = ft_vec3(0.0f, 0.0f, 0.0f);
	obj->scale_obj = ft_vec3(1.0f, 1.0f, 1.0f);
	obj->local_world = ft_ident4();
	return (obj);
}

void	object_destroy(t_object *obj)
{
	free(obj);
}

void	update_object(t_object *obj)
{
	obj->local_world = get_invtransform(obj->pos_obj, obj->rot_obj, obj->scale_obj);
	obj->world_local = get_transform(obj->pos_obj, obj->rot_obj, obj->scale_obj);
}
