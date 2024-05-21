/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_zip_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:14:39 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 20:38:01 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_zip_next(t_dlst_zip *iter, void **out1, void **out2)
{
	void	*data1;
	void	*data2;

	if (!iter->l1_next || !iter->l2_next)
		return (LST_ITER_END);
	data1 = iter->l1_next->data;
	data2 = iter->l2_next->data;
	iter->l1_last = iter->l1_next;
	iter->l2_last = iter->l2_next;
	iter->l1_next = iter->l1_next->next;
	iter->l2_next = iter->l2_next->next;
	iter->index++;
	*out1 = data1;
	*out2 = data2;
	return (LST_OK);
}
