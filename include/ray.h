/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:58:27 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/20 16:59:03 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "ft_vector.h"

typedef struct	s_ray
{
	t_vec3	d;
	t_vec3	o;
	float	t;
}	t_ray;

#endif  // RAY_H