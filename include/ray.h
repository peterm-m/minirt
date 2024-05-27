/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:58:27 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/27 12:03:24 by pedromar         ###   ########.fr       */
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
	float	t_min;
	float	t_max;
}	t_ray;

/*
 * generate ray with origin in cam_pos and direction to pix_coor
*/

t_ray	create_ray(t_camera *cam, t_vec2i *pix_coor);

/*
 * change direction of ray r, ray pass by pix_coor
*/

void	new_direction(t_camera *cam, t_ray *r, t_vec2i *pix_coor);

#endif  // RAY_H