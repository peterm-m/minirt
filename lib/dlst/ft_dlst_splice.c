/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_splice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:04:20 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 21:04:25 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_splice(t_dlst *list1, t_dlst *list2)
{
	return (ft_dlst_splice_at(list1, list2, list1->size));
}
