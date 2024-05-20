/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:45:23 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/20 16:58:12 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

# include "ft_vector.h"

# include "colors.h"
# include "render.h"
# include "geometric.h"
# include "controls.h"
# include "transformation.h"
# include "wrappers.h"
# include "plotter.h"

# ifndef M_PI
#  define M_PI   3.14159265358979323846264338327950288
# endif


void	*mallox(size_t size);
int		ft_plot_points(t_render *r);
int		rt_loop(t_render *r);
int 	ft_end_program(t_render *r);

#endif // MINIRT_H