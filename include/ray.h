/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:58:27 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/13 20:09:28 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include "ft_vector.h"

typedef struct	s_ray
{
	t_vec3	d;
	t_vec3	o;
	float	t;
}	t_ray;

t_vec3	ray_in_t(t_ray *r);

#endif  // MINIRT_H