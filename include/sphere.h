/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:23:52 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/20 13:27:26 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "ray.h"
# include "material.h"
# include "ft_vector.h"

typedef struct	s_sphere
{
	t_vec4	center;
	float	radius;
	float	radius2;
	t_vec4	color;
	bool	(*intersection)(t_ray *r);
	t_vec3	(*get_notmal)(t_vec3 *point);
}	t_sphere;

#endif /* SPHERE_H */


