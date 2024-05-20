/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:00:10 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/20 13:16:12 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "ft_vector.h"

typedef struct	s_material
{
	float	reflectivity;
	float	transmissivity;
	t_vec3	surface_color;
	t_vec3	emission_color;
} t_material;


#endif /* MATERIAL_H*/

