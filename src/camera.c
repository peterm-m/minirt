/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:01:50 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/27 16:30:55 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*camera_new(void)
{
	t_camera	*cam;

	cam = mallox(sizeof(t_camera));
	cam->pos_cam = ft_vec3(0.0f, 0.0f, 0.0f);
	cam->rot_cam = ft_vec3(0.0f, 0.0f, 0.0f);
	cam->scale_cam = ft_vec3(1.0f, 1.0f, 1.0f);
	cam->img_size[IMG_SIZE_X] = DEFAULT_IMGSIZE_X;
	cam->img_size[IMG_SIZE_Y] = DEFAULT_IMGSIZE_Y;
	cam->clipping[CLIP_NEAR] = DEFAULT_CLIPPING_NEAR;
	cam->clipping[CLIP_FAR] = DEFAULT_CLIPPING_FAR;
	cam->aperture[APERTURE_WIDTH] = DEFAULT_APERTURE_WIDTH;
	cam->aperture[APERTURE_HEIGHT] = DEFAULT_APERTURE_HEIGHT;
	cam->focal = 0.0f;
	return (cam);
}

void	camera_destroy(t_camera *cam)
{
	free(cam);
}

void	update_camera(t_camera *cam)
{
	cam->camera_world = get_invtransform(cam->pos_cam, \
		cam->rot_cam, cam->scale_cam);
	cam->world_camera = get_transform(cam->pos_cam, \
		cam->rot_cam, cam->scale_cam);
	cam->canvas_windows.elements[CANVAS_TOP] = \
		((cam->aperture[APERTURE_HEIGHT] / 2.0f) \
		/ cam->focal) * cam->clipping[CLIP_NEAR];
	cam->canvas_windows.elements[CANVAS_RIGHT] = \
		((cam->aperture[APERTURE_WIDTH] / 2.0f) \
		/ cam->focal) * cam->clipping[CLIP_NEAR];
	cam->canvas_windows.elements[CANVAS_BOTTOM] = \
		- cam->canvas_windows.elements[CANVAS_TOP];
	cam->canvas_windows.elements[CANVAS_LEFT] = \
	- cam->canvas_windows.elements[CANVAS_RIGHT];
}

bool	pixel_coordenate(t_camera *cam, t_vec4 v_world, t_vec2i *pix_coor)
{
	t_vec4	v_cam;
	t_vec2	v_screen;
	t_vec2	v_ndc;

	applay_transformation(&cam->camera_world, &v_world, &v_cam);
	v_screen.x = v_cam.x / -v_cam.z * cam->clipping[CLIP_NEAR];
	v_screen.y = v_cam.y / -v_cam.z * cam->clipping[CLIP_NEAR];
	v_ndc.x = (v_screen.x + cam->canvas_windows.elements[CANVAS_RIGHT]) \
			/ (2 * cam->canvas_windows.elements[CANVAS_RIGHT]);
	v_ndc.y = (v_screen.y + cam->canvas_windows.elements[CANVAS_TOP]) \
			/ (2 * cam->canvas_windows.elements[CANVAS_TOP]);
	pix_coor->x = (int)(v_ndc.x * cam->img_size[IMG_SIZE_X]);
	pix_coor->y = (int)((1.0f - v_ndc.y) * cam->img_size[IMG_SIZE_Y]);
	return (v_screen.x < cam->canvas_windows.elements[CANVAS_LEFT] \
		|| v_screen.x > cam->canvas_windows.elements[CANVAS_RIGHT] \
		|| v_screen.y < cam->canvas_windows.elements[CANVAS_BOTTOM] \
		|| v_screen.y > cam->canvas_windows.elements[CANVAS_TOP]);
}

void	reset_camera(t_camera *cam)
{
	cam->pos_cam = ft_vec3(0.0f, 0.0f, 0.0f);
	cam->rot_cam = ft_vec3(0.0f, 0.0f, 0.0f);
	cam->scale_cam = ft_vec3(1.0f, 1.0f, 1.0f);
	cam->img_size[IMG_SIZE_X] = DEFAULT_IMGSIZE_X;
	cam->img_size[IMG_SIZE_Y] = DEFAULT_IMGSIZE_Y;
	cam->clipping[CLIP_NEAR] = DEFAULT_CLIPPING_NEAR;
	cam->clipping[CLIP_FAR] = DEFAULT_CLIPPING_FAR;
	cam->aperture[APERTURE_WIDTH] = DEFAULT_APERTURE_WIDTH;
	cam->aperture[APERTURE_HEIGHT] = DEFAULT_APERTURE_HEIGHT;
	cam->focal = 0.0f;
	update_camera(cam);
}
