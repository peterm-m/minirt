/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bounding_box.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:24:36 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/11 20:35:05 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOUNDING_BOX_H
# define FT_BOUNDING_BOX_H

typedef struct	s_bound2
{
	t_vec2	min;
	t_vec2	max;
}	t_bound2;

typedef struct	s_bound3
{
	t_vec3	min;
	t_vec3	max;
}	t_bound3;

// box_in
// box_area
//

#endif // FT_BOUNDING_BOX_H


