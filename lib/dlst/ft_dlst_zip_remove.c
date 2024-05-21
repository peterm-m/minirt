/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_zip_remove.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:13:39 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 19:58:01 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_zip_remove(t_dlst_zip *iter, void **out1, void **out2)
{
	void	*e1;
	void	*e2;

	if (!iter->l1_last || !iter->l2_last)
		return (LST_ERR_VALUE_NOT_FOUND);
	e1 = unlink(iter->l1, iter->l1_last);
	e2 = unlink(iter->l2, iter->l2_last);
	iter->l1_last = NULL;
	iter->l2_last = NULL;
	if (out1)
		*out1 = e1;
	if (out2)
		*out2 = e2;
	return (LST_OK);
}
