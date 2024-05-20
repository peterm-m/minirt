/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:24:17 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/20 15:56:02 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

int	key_manager(int key, t_render *r)
{
	mlx_destroy_image((r->img->win).mlx, r->img->ptr);
	r->img->ptr = mlx_new_image((r->img->win).mlx, r->img->w,
			r->img->h);
	if (!r->img->ptr)
		exit(EXIT_FAILURE);
	r->img->addr = mlx_get_data_addr(r->img->ptr,
			&(r->img->bpp), &r->img->size_line, &r->img->endian);
	if (key == XK_Escape)
		ft_end_program(r);
	else if (key == XK_space)
		default_camera(r);
	view_manager(key, r);
	model_manger(key, r);
	projection_manager(key, r);
	set_transform(r->cam);
	return (EXIT_SUCCESS);
}

void	view_manager(int key, t_render *r)
{
	r->cam->pos_view.z -= 1.5f * (key == XK_q);
	r->cam->pos_view.z += 1.5f * (key == XK_e);
	r->cam->pos_view.y -= 1.5f * (key == XK_w);
	r->cam->pos_view.y += 1.5f * (key == XK_s);
	r->cam->pos_view.x -= 1.5f * (key == XK_a);
	r->cam->pos_view.x += 1.5f * (key == XK_d);
	r->cam->rot_view.z -= 0.1f * (key == XK_u);
	r->cam->rot_view.z += 0.1f * (key == XK_o);
	r->cam->rot_view.y -= 0.1f * (key == XK_i);
	r->cam->rot_view.y += 0.1f * (key == XK_k);
	r->cam->rot_view.x -= 0.1f * (key == XK_j);
	r->cam->rot_view.x += 0.1f * (key == XK_l);
}

void	model_manger(int key, t_render *r)
{
	r->cam->scale.x += 1.0f * (key == XK_KP_Add);
	r->cam->scale.y += 1.0f * (key == XK_KP_Add);
	r->cam->scale.z += 1.0f * (key == XK_KP_Add);
	r->cam->scale.x -= 1.0f * (key == XK_KP_Subtract);
	r->cam->scale.y -= 1.0f * (key == XK_KP_Subtract);
	r->cam->scale.z -= 1.0f * (key == XK_KP_Subtract);
}

void	projection_manager(int key, t_render *r)
{
	r->cam->proj_max.z += 0.2 * (r->cam->proj_max.z < 5 && key == XK_KP_9);
	r->cam->proj_max.z -= 0.2 * (r->cam->proj_max.z > 0.5 && key == XK_KP_6);
	r->cam->proj_max.y += 0.2 * (r->cam->proj_max.y < 5 && key == XK_KP_8);
	r->cam->proj_max.y -= 0.2 * (r->cam->proj_max.y > 0.5 && key == XK_KP_5);
	r->cam->proj_max.x += 0.2 * (r->cam->proj_max.x < 5 && key == XK_KP_7);
	r->cam->proj_max.x -= 0.2 * (r->cam->proj_max.x > 0.5 && key == XK_KP_4);
	r->cam->proj_min.z += 0.2 * (r->cam->proj_min.z < -0.5 && key == XK_KP_6);
	r->cam->proj_min.z -= 0.2 * (r->cam->proj_min.z > -5 && key == XK_KP_9);
	r->cam->proj_min.y += 0.2 * (r->cam->proj_min.y < -0.5 && key == XK_KP_5);
	r->cam->proj_min.y -= 0.2 * (r->cam->proj_min.y > -5 && key == XK_KP_8);
	r->cam->proj_min.x += 0.2 * (r->cam->proj_min.x < -0.5 && key == XK_KP_4);
	r->cam->proj_min.x -= 0.2 * (r->cam->proj_min.x > -5 && key == XK_KP_7);
}
