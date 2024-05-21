/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_zip_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:12:31 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/22 21:36:41 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst_intern.h"

t_dlst_stat	ft_dlst_zip_replace(t_dlst_zip *iter, void **e,
	void **out1, void **out2)
{
	void	*old1;
	void	*old2;

	if (!iter->l1_last || !iter->l2_last)
		return (LST_ERR_VALUE_NOT_FOUND);
	old1 = iter->l1_last->data;
	old2 = iter->l2_last->data;
	iter->l1_last->data = e[1];
	iter->l2_last->data = e[2];
	if (out1)
		*out1 = old1;
	if (out2)
		*out2 = old2;
	return (LST_OK);
}
