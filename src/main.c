/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:47:54 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/15 18:56:30 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "mlx_minirt.h"
#include "camera.h"
#include "colors.h"

void	ft_image(t_image *img, t_win *win, int w, int h)
{
	img = (t_image *)malloc(sizeof(t_image));
	img->win = *win;
	img->ptr = mlx_new_image(win->mlx, w, h);
	if (!img->ptr)
		exit(EXIT_FAILURE);
	img->addr = mlx_get_data_addr(img->ptr, &(img->bpp),
			&(img->size_line), &(img->endian));
	img->w = w;
	img->h = h;
}

t_win	ft_program(int h, int w, char *str)
{
	void	*mlx_ptr;
	void	*win;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		exit(EXIT_FAILURE);
	win = mlx_new_window(mlx_ptr, w, h, str);
	if (!win)
		exit(EXIT_FAILURE);
	return ((t_win){mlx_ptr, win, w, h});
}

t_render	*set_render(t_win *win)
{
	t_render	*new;

	new = (t_render *)mallox(sizeof(t_render));
	if (!new)
		exit(EXIT_FAILURE);
	ft_image(new, win, 1024, 1024);
	new->cam = new_camera();
	set_transform(new->cam);
	return (new);
}



void	set_control(t_render *r)
{
	mlx_loop_hook(r->img->win.mlx, &ft_plot_map, &r);
}

int main (int argc, char* argv[])
{
#ifdef DEBUG
	/* Debug */
#endif
	(void)argc;
	(void)argv;

	t_win	win =  ft_program(1024, 1024, "Example");

	t_render *r = set_render(&win);
	set_control(r);
	mlx_loop(win.mlx);
	return (EXIT_SUCCESS);
}

