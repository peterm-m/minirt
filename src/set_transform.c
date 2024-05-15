/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:00:08 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/15 18:56:51 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "camera.h"
# include "transformation.h"
# include "minirt.h"

void	set_transform(t_cam *c)
{
	c->model = translate(c->pos_model);
	c->model = ft_mulm4m(rotater(c->rot_model.x,
				ft_vec3(1.0f, 0.0f, 0.0f)), c->model);
	c->model = ft_mulm4m(rotater(c->rot_model.y,
				ft_vec3(0.0f, 1.0f, 0.0f)), c->model);
	c->model = ft_mulm4m(rotater(c->rot_model.z,
				ft_vec3(0.0f, 0.0f, 1.0f)), c->model);
	c->view = rotater(c->rot_view.z, ft_vec3(0.1f, 0.0f, 0.0f));
	c->view = ft_mulm4m(rotater(-c->rot_view.y,
				ft_vec3(0.0f, 1.0f, 0.0f)), c->view);
	c->view = ft_mulm4m(rotater(c->rot_view.x,
				ft_vec3(0.0f, 0.0f, 1.0f)), c->view);
	c->view = ft_mulm4m(translate(c->pos_view), c->view);
		c->proj = orthographicr(c->proj_max, c->proj_min);
	c->trasform = ft_mulm4m(c->model, c->view);
	c->trasform = ft_mulm4m(c->proj, c->trasform);
	c->trasform = ft_mulm4m(c->trasform,
			scale(c->scale));
	c->trasform = ft_mulm4m(c->trasform,
			translate(ft_vec3(100.0f / 2, 100.0f / 2, 0)));
}