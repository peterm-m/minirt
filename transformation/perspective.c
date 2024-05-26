/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:36:59 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/22 18:31:57 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ft_vector.h"

t_matrix4	perspectiver(float fov, float aspect, float near, float far)
{
	t_matrix4	m;
	float		scale;

	m = ft_ident4();
	scale = 1.0f / tanf(fov / 2.0f);
	m.elements[0][0] = scale / aspect;
	m.elements[1][1] = scale;
	m.elements[2][2] = (near + far) / (near - far);
	m.elements[3][2] = (2.0f * near * far) / (near - far);
	m.elements[2][3] = -1.0f;
	return (m);
}

t_matrix4	invperspectiver(t_matrix4 pers_m)
{
	t_matrix4	m;

	m = ft_ident4();
	m.elements[0][0] = 1.0f / pers_m.elements[0][0];
	m.elements[1][1] = 1.0f / pers_m.elements[1][1];
	m.elements[2][2] = 0.0f;
	m.elements[2][3] = 1.0f / pers_m.elements[3][2];
	m.elements[3][3] = pers_m.elements[2][2] * m.elements[2][3];
	m.elements[3][2] = pers_m.elements[2][3];
	return (m);
}

t_matrix4	perspectivel(float fov, float aspect, float near, float far)
{
	t_matrix4	m;

	m = ft_ident4();
	m = perspectiver(fov, aspect, near, far);
	m.elements[2][2] = -m.elements[2][2];
	m.elements[2][3] = -m.elements[2][3];
	return (m);
}

t_matrix4	invperspectivel(t_matrix4 pers_m)
{
	t_matrix4	m;

	m = ft_ident4();
	m.elements[0][0] = 1.0f / pers_m.elements[0][0];
	m.elements[1][1] = 1.0f / pers_m.elements[1][1];
	m.elements[2][2] = 0.0f;
	m.elements[2][3] = 1.0f / pers_m.elements[3][2];
	m.elements[3][3] = pers_m.elements[2][2] * -m.elements[2][3];
	m.elements[3][2] = pers_m.elements[2][3];
	return (m);
}
