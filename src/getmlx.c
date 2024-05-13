/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:49:22 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/13 21:07:36 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_minirt.h"

void	*getmlx(void)
{
	static void	*mlx;

	if (mlx == NULL)
		mlx = mlx_init();
	if (!mlx)
	{
		printf("mlx error\n");
		exit(EXIT_FAILURE);
	}
	return (mlx);
}

t_mlx	*new_mlx(char *name)
{
	t_mlx	*new;

	new = mallox(sizeof(t_mlx));
	new->win = mlx_new_window(getmlx(),
		DEFAULT_WIN_SX,
		DEFAULT_WIN_SX, name);
	if (!new->win)
	{
		printf("make windows error \n");
		exit(EXIT_FAILURE);
	}
	new->im = mlx_new_image(getmlx(), DEFAULT_IMG_SX, DEFAULT_IMG_SY);
	if (!new->im)
	{
		printf("make image error \n");
		exit(EXIT_FAILURE);
	}
	new->data = mlx_get_data_addr(new->im,&(new->bpp),&(new->sl),&(new->endian));
	return (new);
}