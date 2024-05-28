/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:32:15 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/28 12:23:03 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ray.h"

int	rgb_color(t_cy *cy, t_ray *ray)
{
	t_vec3 v = ft_addv3(ray->o, ft_mulv3f(ray->d, ray->t));
	float	intensity = 1.0f - ft_dotv3(normal_cy(&v, cy), ray->d);
	return (set_rgba(ft_vec4(intensity, intensity, intensity, 0.0f)));
}

t_ray	gen_ray(t_render *r, t_vec2i *p)
{
	t_ray	ray;
	float	screen_x;
	float	screen_y;

	screen_x = 2.0f * ((p->x + 0.5f) / r->img->w) - 1.0f;
	screen_y = 1.0f - 2.0f * ((p->y + 0.5f) / r->img->h);
	t_vec3	aux = ft_vec3(0.0f, 0.0f, 0.0f);
	applay_transformation(&r->c->world_camera, &aux, &ray.o);
	aux = ft_vec3(screen_x ,screen_y, -1.0f);
	applay_transformation(&r->c->world_camera, &aux, &ray.d);
	ray.d = ft_divv3f(ray.d, ft_lenv3(ray.d));
	return (ray);
}

static int	rt_trace(t_cy *cy, t_render *r, t_vec2i *p)
{
	t_ray	ray;

	ray = gen_ray(r, p);
	if (interseccion_cy(&ray, cy))
		ft_put_pixel(r->img, p->x, p->y, rgb_color(cy, &ray));
	return (EXIT_SUCCESS);
}

int	plot_loop(t_render *r)
{
	t_cy	cy;
	t_vec2i	p;

	cy.center = ft_vec3(0.0f, 0.0f, -2.0f);
	cy.radius = 0.5f;
	cy.height = 1.0f;
	cy.normal = ft_vec3(0.0f,1.0f,0.0f);
	p.x = -1;
	while (++p.x < 1024)
	{
		p.y = -1;
		while (++p.y < 1024)
			rt_trace(&cy, r, &p);
	}
	ft_put_image_to_window(r->img);
	return (EXIT_SUCCESS);
}
