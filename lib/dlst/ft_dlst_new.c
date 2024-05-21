/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:09:06 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/07 15:52:16 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_new(t_dlst **out)
{
	t_dlst_conf	lc;

	ft_dlst_conf_init(&lc);
	return (ft_dlst_new_conf(&lc, out));
}
