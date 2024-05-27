/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:58:35 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/27 16:59:23 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATION_H
# define TRANSFORMATION_H

# include "ft_vector.h"

t_matrix4	get_transform(t_vec3 pos, t_vec3 rot, t_vec3 sca);
t_matrix4	get_invtransform(t_vec3 pos, t_vec3 rot, t_vec3 sca);
void		applay_transformation(t_matrix4 *m, t_vec3 *v, t_vec3 *d);

t_matrix4	translate(t_vec3 translation);
t_matrix4	inv_translate(t_vec3 translation);

t_matrix4	scale(t_vec3 scale);
t_matrix4	inv_scale(t_vec3 scale);

t_matrix4	rotater(float a, t_vec3 axis);
t_matrix4	rotatel(float a, t_vec3 axis);
t_matrix4	inv_rotate(float a, t_vec3 axis);

t_matrix4	lookatr(t_vec3 target, t_vec3 updir, t_vec3 eye);
t_matrix4	lookatl(t_vec3 target, t_vec3 updir, t_vec3 eye);
t_matrix4	invlookat(t_matrix4 lookat_m);

t_matrix4	orthographicr(t_vec3 max, t_vec3 min);
t_matrix4	orthographicl(t_vec3 max, t_vec3 min);
t_matrix4	invorthographic(t_matrix4 ortho_m);

t_matrix4	perspectiver(float fov, float aspect, float near, float far);
t_matrix4	invperspectiver(t_matrix4 pers_m);
t_matrix4	perspectivel(float fov, float aspect, float near, float far);
t_matrix4	invperspectivel(t_matrix4 pers_m);

#endif // TRANSFORMATION_H