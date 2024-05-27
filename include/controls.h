/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:18:43 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/27 12:38:21 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# include "render.h"
# include "wrappers.h"
// keyboard control
# include <X11/keysym.h>
# include <X11/keysymdef.h>

// mouse control
# define MOUSE_LEFT			1
# define MOUSE_RIGHT		2
# define MOUSE_CENTER		3
# define MOUSE_ROLL_DOWN	4
# define MOUSE_ROLL_UP		5

# define  NUM_MOUSE_BUTTON	5

// definitions
# define VIEW_POS_DX	1
# define VIEW_POS_DY	1
# define VIEW_POS_DZ	1

# define VIEW_ROT_DX	1
# define VIEW_ROT_DY	1
# define VIEW_ROT_DZ	1

# define MODEL_POS_DX	1
# define MODEL_POS_DY	1
# define MODEL_POS_DZ	1

# define MODEL_ROT_DX	1
# define MODEL_ROT_DY	1
# define MODEL_ROT_DZ	1

# define PROJ_MAX_DX	1
# define PROJ_MAX_DY	1
# define PROJ_MAX_DZ	1

# define PROJ_MIN_DX	1
# define PROJ_MIN_DY	1
# define PROJ_MIN_DZ	1

# define PROJ_TYPE_PROJ	0
# define PROJ_TYPE_ORTHO	1
# define PROJ_TYPE_PROJSYM	2
# define PROJ_TYPE_ORTHOSYM	3

void	set_control(t_render *r);
int		key_manager(int key, t_render *render);
int		mouse_motion_manager(int x, int y, t_render *r);
int		mouse_button_manager(int buttom, int x, int y, t_render *r);
int		mouse_button_release(int buttom, int x, int y, t_render *r);

void	view_manager(int key, t_render *r);
void	model_manger(int key, t_render *r);
void	projection_manager(int key, t_render *r);
void	key_scale(void );

typedef struct s_control
{
	char	mouse[NUM_MOUSE_BUTTON];
	int		press_x;
	int		press_y;
	int		release_x;
	int		release_y;
}	t_control;

#endif // CONTROLS_H
