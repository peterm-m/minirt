/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:38:01 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/27 16:27:52 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_matrix4	rotater(float a, t_vec3 axis)
{
	t_matrix4	m;
	float		s;
	float		c;
	float		cv;

	s = sinf(a);
	c = cosf(a);
	cv = 1.0f - c;
	m = ft_ident4();
	axis = ft_divv3f(axis, ft_lenv3(axis));
	m.elements[0][0] = (axis.x * axis.x * cv) + c;
	m.elements[0][1] = (axis.x * axis.y * cv) + (axis.z * s);
	m.elements[0][2] = (axis.x * axis.z * cv) - (axis.y * s);
	m.elements[1][0] = (axis.y * axis.x * cv) - (axis.z * s);
	m.elements[1][1] = (axis.y * axis.y * cv) + c;
	m.elements[1][2] = (axis.y * axis.z * cv) + (axis.x * s);
	m.elements[2][0] = (axis.z * axis.x * cv) + (axis.y * s);
	m.elements[2][1] = (axis.z * axis.y * cv) - (axis.x * s);
	m.elements[2][2] = (axis.z * axis.z * cv) + c;
	return (m);
}

t_matrix4	rotatel(float a, t_vec3 axis)
{
	return (rotater(-a, axis));
}

t_matrix4	inv_rotate(float a, t_vec3 axis)
{
	return (rotater(-a, axis));
}
