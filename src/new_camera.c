/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:51:21 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/15 18:23:11 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "camera.h"
# include "minirt.h"

# define PROJ_TYPE_ORTHO	1

t_cam	*new_camera(void)
{
	t_cam	*new_cam;

	new_cam = (t_cam *)mallox(sizeof(t_cam));
	new_cam->proj_type = PROJ_TYPE_ORTHO;
	new_cam->scale = ft_vec3(100.0f, 100.0f , 100.0f);
	new_cam->pos_view = ft_vec3(100.0f / 1.5f, 0.0f, 0.0f);
	new_cam->rot_view = ft_vec3(0.0f, 0.0f, 0.0f);
	new_cam->pos_model = ft_vec3(0.0f, 0.0f, 0.0f);
	new_cam->rot_model = ft_vec3(5.38f, 0.016815f, 5.64f);
	new_cam->proj_max = ft_vec3(1.0f, 1.0f, 1.0f);
	new_cam->proj_min = ft_vec3(-1.0, -1.0, -1.0f);
	return (NULL);
}
