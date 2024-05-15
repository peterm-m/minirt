/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_minirt.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:37:29 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/15 18:47:36 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_MINIRT_H
# define MLX_MINIRT_H

# include	"minirt.h"
# include	"mlx.h"
# include	"mlx_int.h"

# define	DEFAULT_WIN_SX		242
# define	DEFAULT_WIN_SY		242

# define	DEFAULT_image_SX		42
# define	DEFAULT_image_SY		42

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		w;
	int		h;
}	t_win;

typedef struct s_image
{
	t_win	win;
	void	*ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		w;
	int		h;
}	t_image;

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

typedef struct s_render
{
	t_image	*img;
	t_cam	*cam;
}	t_render;

void	*getmlx(void);

#endif // MLX_MINIRT_H