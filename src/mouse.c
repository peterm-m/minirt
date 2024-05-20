/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:26:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/20 15:50:03 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mouse_motion_manager(int x, int y, t_render *r)
{
	mlx_destroy_image((r->img->win).mlx, r->img->ptr);
	r->img->ptr = mlx_new_image((r->img->win).mlx, r->img->w,
			r->img->h);
	if (!r->img->ptr)
		exit(EXIT_FAILURE);
	r->img->addr = mlx_get_data_addr(r->img->ptr,
			&(r->img->bpp), &r->img->size_line, &r->img->endian);
	if (r->cam->button_press == MOUSE_LEFT)
		r->cam->rot_model = ft_vec3(
				r->cam->rot_model.x,
				fmod((float)x / 100, (2 * M_PI)),
				r->cam->rot_model.z);
	if (r->cam->button_press == MOUSE_RIGHT)
		r->cam->rot_model = ft_vec3(
				fmod((float)y / 100, (2 * M_PI)),
				r->cam->rot_model.y,
				r->cam->rot_model.z);
	if (r->cam->button_press == MOUSE_CENTER)
		r->cam->rot_model = ft_vec3(
				r->cam->rot_model.x,
				r->cam->rot_model.y,
				fmod((float)y / 100, (2 * M_PI)));
	set_transform(r->cam);
	return (0);
}

int	mouse_button_manager(int buttom, int x, int y, t_render *r)
{
	(void) x;
	(void) y;
	if (buttom != 0)
		r->cam->button_press = buttom;
	if (r->cam->button_press == MOUSE_ROLL_UP)
		projection_manager(XK_KP_Add, r);
	if (r->cam->button_press == MOUSE_ROLL_DOWN)
		projection_manager(XK_KP_Subtract, r);
	return (buttom);
}

int	mouse_button_release(int buttom, int x, int y, t_render *r)
{
	(void) x;
	(void) y;
	r->cam->button_press = 0;
	return (buttom);
}
