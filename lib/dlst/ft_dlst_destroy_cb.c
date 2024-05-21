/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_destroy_cb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:25:59 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 21:27:54 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

void	ft_dlst_destroy_cb(t_dlst *list, void (*cb) (void*))
{
	ft_dlst_remove_all_cb(list, cb);
	list->mem_free(list);
}
