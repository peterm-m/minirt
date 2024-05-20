/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:49:22 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/20 15:51:36 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*ft_getmlx(void)
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

void	*ft_new_image(int w, int h)
{
	void	*ptr;

	ptr = mlx_new_image(ft_getmlx(), w, h);
	if (!ptr)
	{
		printf("mlx error\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

void	*ft_new_windows(int w, int h, char *name)
{
	void	*win;

	win = mlx_new_window(ft_getmlx(), w, h, name);
	if (!win)
	{
		printf("mlx error\n");
		exit(EXIT_FAILURE);
	}
	return (win);
}

void	*mallox(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
		exit (EXIT_FAILURE);
	return (new);
}
