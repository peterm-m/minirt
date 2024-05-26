/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _colors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:21:35 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/26 14:16:21 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

int	set_rgba(t_vec4 c)
{
	return (((int)(RGB_RANGE_MAX * c.b)) \
		+ ((int)(RGB_RANGE_MAX * c.g) << 8) \
		+ ((int)(RGB_RANGE_MAX * c.r) << 16) \
		+ ((int)(RGB_RANGE_MAX * c.a) << 24));
}

t_vec4	get_rgba(float color)
{
	t_vec4	c;

	c.r = (((unsigned int)color >> 16) & 0xFF);
	c.g = (((unsigned int)color >> 8) & 0xFF);
	c.b = (((unsigned int)color) & 0xFF);
	c.a = 0.0f;
	return (c);
}