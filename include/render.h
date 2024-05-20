/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:24:37 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/20 15:59:53 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include	"ft_vector.h"
# include	"geometric.h"
# include	"minirt.h"

# define	DEFAULT_WIN_SX		1024
# define	DEFAULT_WIN_SY		1024

# define	DEFAULT_image_SX		42
# define	DEFAULT_image_SY		42

# define PROJ_TYPE_ORTHO	1

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

typedef struct s_cam
{
	t_vec3		pos_view;
	t_vec3		rot_view;
	t_vec3		pos_model;
	t_vec3		rot_model;
	t_vec3		proj_max;
	t_vec3		proj_min;
	t_vec3		scale;
	int			proj_type;
	int			button_press;
	t_matrix4	view;
	t_matrix4	model;
	t_matrix4	proj;
	t_matrix4	trasform;
}	t_cam;

//todo:
//	render: type
//	Segun type se interpreta points
//	actualmente solo se unen los puntos

typedef struct s_render
{
	t_image		*img;
	t_cam		*cam;
	t_point		*p;
	int			n_point;
}	t_render;

void	new_camera(t_render *r);
void	set_transform(t_cam *c);
void	default_camera(t_render *r);

#endif // RENDER_H