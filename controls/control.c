/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:25:44 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/23 20:17:37 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_control(t_render *r)
{
	mlx_hook(r->img->win.win, 2, 1L << 0, &key_manager, r);
	mlx_hook(r->img->win.win, 3, 1L << 0L, &key_manager, r);
	mlx_hook(r->img->win.win, 4, 1L << 2, &mouse_button_manager, r);
	mlx_hook(r->img->win.win, 5, 1L << 3, &mouse_button_release, r);
	mlx_hook(r->img->win.win, 6, 1L << 6, &mouse_motion_manager, r);
	mlx_hook(r->img->win.win, 17, 0L, &ft_end_program, r);
	mlx_loop_hook(r->img->win.mlx, &plot_loop, r);
}

int	ft_end_program(t_render *r)
{
	mlx_destroy_image((r->img->win).mlx, r->img->ptr);
	mlx_destroy_window((r->img->win).mlx, (r->img->win).win);
	return (EXIT_SUCCESS);
}
