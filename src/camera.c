/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:51:21 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/20 15:51:24 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	set_transform(t_cam *c)
{
	c->model = translate(c->pos_model);
	c->model = ft_mulm4m(rotater(c->rot_model.x, ft_vec3(1.0f, 0.0f, 0.0f)), c->model);
	c->model = ft_mulm4m(rotater(c->rot_model.y, ft_vec3(0.0f, 1.0f, 0.0f)), c->model);
	c->model = ft_mulm4m(rotater(c->rot_model.z, ft_vec3(0.0f, 0.0f, 1.0f)), c->model);
	c->view = rotater(c->rot_view.z, ft_vec3(0.1f, 0.0f, 0.0f));
	c->view = ft_mulm4m(rotater(-c->rot_view.y, ft_vec3(0.0f, 1.0f, 0.0f)), c->view);
	c->view = ft_mulm4m(rotater(c->rot_view.x, ft_vec3(0.0f, 0.0f, 1.0f)), c->view);
	c->view = ft_mulm4m(translate(c->pos_view), c->view);
	if (c->proj_type == PROJ_TYPE_ORTHO)
		c->proj = orthographicr(c->proj_max, c->proj_min);
	else if (c->proj_type == PROJ_TYPE_PROJ)
		perspectiver(1, 1, 1, 1);
	c->trasform = ft_mulm4m(c->model, c->view);
	c->trasform = ft_mulm4m(c->proj, c->trasform);
	c->trasform = ft_mulm4m(c->trasform, scale(c->scale));
	c->trasform = ft_mulm4m(c->trasform, translate(ft_vec3( 1024 / 2,  1024 / 2, 0)));
}


void	default_camera(t_render *r)
{
	r->cam->proj_type = PROJ_TYPE_ORTHO;
	r->cam->scale = ft_vec3(1024 / 4, 1024 / 4, 1.0f);
	r->cam->pos_view = ft_vec3(0.0f, 0.0f, 0.0f);
	r->cam->rot_view = ft_vec3(0.0f, 0.0f, 0.0f);
	r->cam->pos_model = ft_vec3(0.0f, 0.0f, 0.0f);
	r->cam->rot_model = ft_vec3(0.0f, 0.0f, 0.0f);
	r->cam->proj_max = ft_vec3(1.0f, 1.0f, 1.0f);
	r->cam->proj_min = ft_vec3(-1.0, -1.0, -1.0f);
}

void	new_camera(t_render *r)
{
	r->cam = (t_cam *) mallox(sizeof(t_cam));
	if (!r->cam)
		exit(EXIT_FAILURE);
	default_camera(r);
	set_transform(r->cam);
}
