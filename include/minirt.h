/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:45:23 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/27 16:56:34 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

# include "ft_vector.h"

# include "colors.h"
# include "geometric.h"
# include "object.h"
# include "camera.h"
# include "render.h"
# include "ray.h"
# include "controls.h"
# include "transformation.h"
# include "wrappers.h"

# include "plotter.h"

# ifndef M_PI
#  define M_PI   3.14159265358979323846264338327950288
# endif

void	*mallox(size_t size);
int		plot_loop(t_render *r);
int		ft_plot_points(t_render *r);
//
int		raster_loop(t_render *r);
int		raytracer_loop(t_render *r);
//
int		ft_end_program(t_render *r);

#endif // MINIRT_H
