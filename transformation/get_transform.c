/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:12:48 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/27 11:54:22 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "transformation.h"

t_matrix4	get_transform(t_vec3 pos, t_vec3 rot, t_vec3 sca)
{
	t_matrix4	m;

	m = ft_ident4();
	m = ft_mulm4m(rotater(rot.x, ft_vec3(1.0f, 0.0f, 0.0f)), m);
	m = ft_mulm4m(rotater(rot.y, ft_vec3(0.0f, 1.0f, 0.0f)), m);
	m = ft_mulm4m(rotater(rot.z, ft_vec3(0.0f, 0.0f, 1.0f)), m);
	m = ft_mulm4m(translate(pos), m);
	m = ft_mulm4m(scale(sca), m);
	return (m);
}

t_matrix4	get_invtransform(t_vec3 pos, t_vec3 rot, t_vec3 sca)
{
	t_matrix4	m;

	m = ft_ident4();
	m = ft_mulm4m(inv_scale(sca), m);
	m = ft_mulm4m(inv_translate(pos), m);
	m = ft_mulm4m(inv_rotate(rot.z, ft_vec3(0.0f, 0.0f, 1.0f)), m);
	m = ft_mulm4m(inv_rotate(rot.y, ft_vec3(0.0f, 1.0f, 0.0f)), m);
	m = ft_mulm4m(inv_rotate(rot.x, ft_vec3(1.0f, 0.0f, 0.0f)), m);
	return (m);
}
