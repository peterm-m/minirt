/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:58:08 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/26 13:31:09 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "minirt.h"

// all distances in mm

# define DEFAULT_FOCAL 35

# define IMG_SIZE_X 0
# define IMG_SIZE_Y 1

# define DEFAULT_IMGSIZE_X 1024
# define DEFAULT_IMGSIZE_Y 1024

# define CLIP_NEAR 0
# define CLIP_FAR 1

# define DEFAULT_CLIPPING_NEAR 0.1f  
# define DEFAULT_CLIPPING_FAR 1000.0f

# define APERTURE_WIDTH 0
# define APERTURE_HEIGHT 1

# define DEFAULT_APERTURE_WIDTH 24.892f  
# define DEFAULT_APERTURE_HEIGHT 11.3284f

# define CANVAS_TOP 0
# define CANVAS_BOTTOM 1
# define CANVAS_RIGHT 2
# define CANVAS_LEFT 3

typedef struct s_vec2i
{
	struct
	{
		int	y;
		int	x;
	};
	int	elements[2];
}	t_vec2i;

typedef struct s_camera
{
	float		focal;
	int			img_size[2];
	float		clipping[2];
	float		aperture[2];
	float		angle_of_view;
	t_vec4		canvas_windows;
	t_vec3		pos_cam;
	t_vec3		rot_cam;
	t_vec3		scale_cam;
	t_matrix4	camera_world;
	t_matrix4	world_camera;
}	t_camera;

/*
 *	create new camera with n points
*/
t_camera	*camera_new(void);

/*
 *	destroy camera cam
*/
void		camera_destroy(t_camera *cam);

/*
 *	update position, orientation and scale camera
 *		Direct transformation:
 *		RotX * RotY * RotZ * Trasn * Scale
*/
void		update_camera(t_camera *cam);

/*
 *	updata angle_view, near and far of camera
*/
void		update_camera_projection(t_camera *cam);

/*
 * reset camera
*/
void		reset_camera(t_camera *cam);

/*
 * put pixel coordinate in pix_coor. return this coordinates is in screen
*/
bool		pixel_coordenate(t_camera *cam, t_vec4 v_world, t_vec2i *pix_coor);

#endif