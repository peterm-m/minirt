/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:48:06 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/26 13:50:35 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "ft_vector.h"

# define NO_COLOR    "\x1b[0m"
# define RED         "\x1b[31m"
# define GREEN       "\x1b[32m"
# define BROWN       "\x1b[33m"
# define BLUE        "\x1b[34m"
# define MAGENTA     "\x1b[35m"
# define CYAN        "\x1b[36m"
# define GRAY        "\x1b[37m"

# define RGB_RANGE_MAX 255
# define RGB_RANGE_MIN 0

int		set_rgba(t_vec4	c);
t_vec4	get_rgba(float color);

#endif // COLORS_H
