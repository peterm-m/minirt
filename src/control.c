/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:25:44 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/15 18:47:38 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "minirt.h"

int ft_end_program(t_render *r)
{
	mlx_destroy_image((r->img->win).mlx, r->img->ptr);
	mlx_destroy_window((r->img->win).mlx, (r->img->win).win);
	return (EXIT_SUCCESS);
}

int		ft_plot_map(t_render *r)
{
	(void *)r;
	return (EXIT_SUCCESS);
}
