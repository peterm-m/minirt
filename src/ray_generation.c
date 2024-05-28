/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_generation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:45:57 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/28 12:58:37 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// TODO
t_ray	create_ray(t_camera *cam, t_vec2i *pix_coor)
{
	t_ray	r;

	(void)cam;
	(void)pix_coor;
	return (r);
}

// TODO
void	new_direction(t_camera *cam, t_ray *r, t_vec2i *pix_coor)
{
	return ;
}


t_vec3	point_at(float t, t_ray *r)
{
	return (ft_addv3(r->o ,ft_mulv3f(r->d, t)));
}