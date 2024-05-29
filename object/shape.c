/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:20:57 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/29 13:05:19 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	new_shape(t_shape_type type)
{
	t_shape	sh;

	if (type == sh_sphere)
		sh.sp = mallox(sizeof(t_sp));
	else if (type == sh_box)
		sh.bx = mallox(sizeof(t_bx));
	else if (type == sh_plane)
		sh.pl = mallox(sizeof(t_pl));
	else if (type == sh_cylinder)
		sh.cy = mallox(sizeof(t_cy));
	return (sh);
}

void	delete_shape(t_shape_type type, t_shape sh)
{
	if (type == sh_sphere)
		free(sh.sp);
	else if (type == sh_box)
		free(sh.bx);
	else if (type == sh_plane)
		free(sh.pl);
	else if (type == sh_cylinder)
		free(sh.cy);
}