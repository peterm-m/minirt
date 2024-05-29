/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:55:03 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/29 16:45:41 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "ft_vector.h"

typedef enum e_light_type
{
	lgh_ambient,
	lgh_point
}	t_light_type;

typedef struct	s_light
{
	t_light_type	type;
	t_vec3			pos;
	t_vec4			color;
	float			brightness;
}	t_light;

#endif // LIGHT_H