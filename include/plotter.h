/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:37:29 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/20 16:58:15 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLOTTER_H
# define PLOTTER_H

# include	"minirt.h"

void	ft_put_pixel(t_image *img, int x, int y, int c);
int		ft_plot_line(t_render *r, t_point p0, t_point p1);

void	points_axis(t_render *r);
void	points_box(t_render *r);

#endif // PLOTTER_H