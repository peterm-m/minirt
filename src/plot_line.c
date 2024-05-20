/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:40:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/20 16:14:44 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	ft_put_pixel(t_image *img, int x, int y, int c)
{
	char	*dst;

	if (x > 0 && y > 0 && x < img->w && y < img->h)
	{
		dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
		*(unsigned int *) dst = (unsigned int)c;
	}
}

static void	draw_line(t_image *img, t_line l)
{
	while (l.i-- != 0)
	{
		ft_put_pixel(img, l.x0, l.y0, set_rgba(ft_addv4(l.c,
					ft_mulv4f(l.dc, l.i))));
		l.x1 -= l.dx;
		if (l.x1 < 0)
		{
			l.x1 += l.dm;
			l.x0 += l.sx;
		}
		l.y1 -= l.dy;
		if (l.y1 < 0)
		{
			l.y1 += l.dm;
			l.y0 += l.sy;
		}
		l.z1 -= l.dz;
		if (l.z1 < 0)
		{
			l.z1 += l.dm;
			l.z0 += l.sz;
		}
	}
}

int	ft_plot_line(t_render *r, t_point p0, t_point p1)
{
	t_line	l;

	p0.r = ft_mulm4v(r->cam->trasform, p0.r);
	p1.r = ft_mulm4v(r->cam->trasform, p1.r);
	l.dx = abs((int)p1.r.x - (int)p0.r.x);
	l.dy = abs((int)p1.r.y - (int)p0.r.y);
	l.dz = abs((int)p1.r.z - (int)p0.r.z);
	l.sx = (p0.r.x < p1.r.x) - (p0.r.x >= p1.r.x);
	l.sy = (p0.r.y < p1.r.y) - (p0.r.y >= p1.r.y);
	l.sz = (p0.r.z < p1.r.z) - (p0.r.z >= p1.r.z);
	l.dm = MAX(MAX(l.dx, l.dy), l.dz);
	l.i = l.dm;
	l.x1 = l.dm / 2;
	l.y1 = l.dm / 2;
	l.z1 = l.dm / 2;
	l.x0 = (int) p0.r.x;
	l.y0 = (int) p0.r.y;
	l.z0 = (int) p0.r.z;
	l.c = p0.color;
	l.dc = ft_divv4f(ft_subv4(p1.color, p0.color), (float)l.dm);
	draw_line(r->img, l);
	return (EXIT_SUCCESS);
}

int	ft_plot_points(t_render *r)
{
	int	i;

	i = 0;
	while (i < r->n_point -1)
	{
		ft_plot_line(r, r->p[i], r->p[i + 1]);
		ft_plot_line(r, r->p[i +1], r->p[i]);
		i++;
	}
	mlx_put_image_to_window(r->img->win.mlx, r->img->win.win,
	r->img->ptr, 0, 0);
	return (EXIT_SUCCESS);
}