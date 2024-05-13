/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traslation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:38:08 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/13 20:13:45 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_matrix4	translate(t_vec3 translation)
{
	t_matrix4	m;

	m = ft_ident4();
	m.elements[3][0] = translation.x;
	m.elements[3][1] = translation.y;
	m.elements[3][2] = translation.z;
	return (m);
}

t_matrix4	inv_translate(t_matrix4 translation_m)
{
	t_matrix4	m;

	m = translation_m;
	m.elements[3][0] = -m.elements[3][0];
	m.elements[3][1] = -m.elements[3][1];
	m.elements[3][2] = -m.elements[3][2];
	return (m);
}
