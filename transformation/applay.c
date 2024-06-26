/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applay.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:12:48 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/25 19:37:32 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "transformation.h"

void	applay_transformation(t_matrix4 *m, t_vec3 *v, t_vec3 *d)
{
	t_vec4	aux;

	aux = ft_mulm4v(*m, ft_vec4(v->x, v->y, v->z, 1.0f));
	d->x = aux.x / aux.w;
	d->y = aux.y / aux.w;
	d->z = aux.z / aux.w;
}
