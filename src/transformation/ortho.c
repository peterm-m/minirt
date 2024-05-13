/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ortho.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:37:07 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/13 20:13:28 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_matrix4	orthographicr(t_vec3 max, t_vec3 min)
{
	t_matrix4	m;

	m = ft_mat4();
	m.elements[0][0] = 2.0f / (max.x - min.x);
	m.elements[1][1] = 2.0f / (max.y - min.y);
	m.elements[2][2] = 2.0f / (min.z - max.z);
	m.elements[3][3] = 1.0f;
	m.elements[3][0] = (min.x + max.x) / (min.x - max.x);
	m.elements[3][1] = (min.y + max.y) / (min.y - max.y);
	m.elements[3][2] = (min.z + max.z) / (min.z - max.z);
	return (m);
}

t_matrix4	orthographicl(t_vec3 max, t_vec3 min)
{
	t_matrix4	m;

	m = orthographicr(max, min);
	m.elements[2][2] = -m.elements[2][2];
	return (m);
}

t_matrix4	invorthographic(t_matrix4 ortho_m)
{
	t_matrix4	m;

	m = ft_mat4();
	m.elements[0][0] = 1.0f / ortho_m.elements[0][0];
	m.elements[1][1] = 1.0f / ortho_m.elements[1][1];
	m.elements[2][2] = 1.0f / ortho_m.elements[2][2];
	m.elements[3][3] = 1.0f;
	m.elements[3][0] = -ortho_m.elements[3][0] * m.elements[0][0];
	m.elements[3][1] = -ortho_m.elements[3][1] * m.elements[1][1];
	m.elements[3][2] = -ortho_m.elements[3][2] * m.elements[2][2];
	return (m);
}
