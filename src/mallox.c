/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:51:33 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/13 20:55:47 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*mallox(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
		exit (EXIT_FAILURE);
	return (new);
}
