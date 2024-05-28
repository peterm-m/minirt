/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:58:27 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/28 14:13:37 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "camera.h"
# include "ft_vector.h"

typedef struct s_hit
{
	t_vec3	p;
	t_vec3	nornal;
	t_vec2	tex;
}	t_hit;

typedef struct s_ray
{
	t_vec3	d;
	t_vec3	o;
	float	t;
}	t_ray;

/*
 * generate ray with origin in cam_pos and direction to pix_coor
*/

t_ray	create_ray(t_camera *cam, t_vec2i *pix_coor);

/*
 * change direction of ray r, ray pass by pix_coor
*/

void	new_direction(t_camera *cam, t_ray *r, t_vec2i *pix_coor);

/*
 * return point = r->d * t + r->o
*/

t_vec3	point_at(float t, t_ray *r);

#endif  // RAY_H