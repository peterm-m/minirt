/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_minirt.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:37:29 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/13 19:49:39 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MINIRT_H
# define MLX_MINIRT_H

# include	"mlx.h"
# include	"mlx_int.h"

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*im;
	int		bpp;
	int		sl;
	int		endian;
	char	*data;
}	t_mlx;

void	*getmlx(void);

#endif // MLX_MINIRT_H