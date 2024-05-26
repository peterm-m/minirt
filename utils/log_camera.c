/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:51:21 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/26 13:41:52 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	print_camera(t_camera *cam)
{
	printf("\e[1;1H\e[2J\n");
	printf("focal: %f \n" \
			"img_size: x %d y %d\n"
			"AOV: %f \n" \
			"apperture x %f y %f \n" \
			"clipping: x %f y %f\n", \
			cam->focal, \
			cam->img_size[0], cam->img_size[1], \
			cam->angle_of_view, \
			cam->aperture[0], cam->aperture[1], \
			cam->clipping[0], cam->clipping[1]);
	printf("--->canvas_windows\n");
	printv4(cam->canvas_windows);
	printf("--->pos_cam\n");
	printv3(cam->pos_cam);
	printf("--->rot_cam\n");
	printv3(cam->rot_cam);
	printf("--->scale_cam\n");
	printv3(cam->scale_cam);
	printf("--->camera_world\n");
	printm4(cam->camera_world);
	printf("--->world_camera\n");
	printm4(cam->world_camera);
}