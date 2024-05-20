/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:21:35 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/20 15:51:20 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

unsigned int	set_rgba(t_vec4	c)
{
	return ((unsigned int) c.b
		| (unsigned int) c.g << 8
		| (unsigned int) c.r << 16);
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