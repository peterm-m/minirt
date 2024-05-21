/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_add_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:26:47 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 19:26:57 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_add_all(t_dlst *list1, t_dlst *list2)
{
	if (list1->size == 0)
		return (add_all_to_empty(list1, list2));
	return (ft_dlst_add_all_at(list1, list2, list1->size));
}
