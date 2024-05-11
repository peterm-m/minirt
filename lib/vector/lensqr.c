/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lensqr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:33:16 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/06 21:34:31 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_lensqrv2(t_vec2 v)
{
	return (v.x * v.x + v.y * v.y);
}

float	ft_lensqrv3(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

float	ft_lensqrv4(t_vec4 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}
