/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:45:23 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/29 16:45:44 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>//

# include "ft_vector.h"

# include "colors.h"
# include "geometric.h"
# include "shape.h"
# include "object.h"
# include "camera.h"
# include "render.h"
# include "light.h"
# include "ray.h"
# include "controls.h"
# include "transformation.h"
# include "wrappers.h"
# include "get_next_line.h"

# include "plotter.h"

# ifndef M_PI
#  define M_PI   3.14159265358979323846264338327950288
# endif

typedef struct s_scene
{
	t_object	*objs;
	t_camera	*cams;
	t_light		*lights;
}				t_scene;

int		ft_parser(t_scene *scene, int argc, char **argv);
//
void	*mallox(size_t size);
int		render_loop(t_render *r);
int		ft_plot_points(t_render *r);
//
int		raster_loop(t_render *r);
int		raytracer_loop(t_render *r);
//
int		ft_end_program(t_render *r);

#endif // MINIRT_H
