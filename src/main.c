/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:47:54 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/29 11:35:02 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_image(t_render *r, t_win *win, int w, int h)
{
	r->img = (t_image *) mallox(sizeof(t_image));
	r->img->win = *win;
	r->img->ptr = ft_new_image(w, h);
	r->img->addr = mlx_get_data_addr(r->img->ptr, &(r->img->bpp),
			&(r->img->size_line), &(r->img->endian));
	r->img->w = w;
	r->img->h = h;
}

t_win	ft_program(int h, int w, char *str)
{
	void	*win;

	win = ft_new_windows(w, h, str);
	return ((t_win){ft_getmlx(), win, w, h});
}

t_render	*set_render(t_win *win)
{
	t_render	*new;

	new = (t_render *)mallox(sizeof(t_render));
	new->c = camera_new();
	ft_image(new, win, 1024, 1024);
	return (new);
}


int main (int argc, char* argv[])
{
#ifdef DEBUG
	/* Debug */
#endif
	(void)argc;
	(void)argv;

	printf("MINIRT %s %s\n", __DATE__, __TIME__);
	t_win	win =  ft_program(1024, 1024, "minirt");
	t_render *r = set_render(&win);
	set_control(r);
	mlx_loop(win.mlx);
	return (EXIT_SUCCESS);
}
