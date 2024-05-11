/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:45:38 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/19 19:29:17 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printv2(t_vec2 v)
{
	printf("%f %f \n", v.x, v.y);
}

void	printv3(t_vec3 v)
{
	printf("%f %f %f \n", v.x, v.y, v.z);
}

void	printv4(t_vec4 v)
{
	printf("%f %f %f %f \n", v.x, v.y, v.z, v.w);
}
