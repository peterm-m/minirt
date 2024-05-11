/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:49:22 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/11 19:35:15 by pedromar         ###   ########.fr       */
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