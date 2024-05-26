/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:43:41 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/26 18:12:36 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRIC_H
# define GEOMETRIC_H


# include "minirt.h"
# include <sys/param.h>

typedef struct s_point
{
	t_vec4	r;
	t_vec4	color;
}	t_point;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		dz;
	int		sx;
	int		sy;
	int		sz;
	int		x0;
	int		y0;
	int		z0;
	int		x1;
	int		y1;
	int		z1;
	int		dm;
	int		i;
	t_vec4	c;
	t_vec4	dc;
}	t_line;

#endif