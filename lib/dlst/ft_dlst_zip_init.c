/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_zip_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:38:33 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 20:57:12 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

void	ft_dlst_zip_init(t_dlst_zip *iter, t_dlst *l1, t_dlst *l2)
{
	iter->index = 0;
	iter->l1 = l1;
	iter->l2 = l2;
	iter->l1_last = NULL;
	iter->l2_last = NULL;
	iter->l1_next = l1->head;
	iter->l2_next = l2->head;
}
