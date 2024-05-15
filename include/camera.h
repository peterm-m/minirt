/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:45:01 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/15 18:23:02 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "ft_vector.h"

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

t_cam	*new_camera(void);
void	set_transform(t_cam *c);

#endif // CAMERA_H