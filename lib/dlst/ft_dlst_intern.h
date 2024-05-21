/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_intern.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:25:50 by pedro             #+#    #+#             */
/*   Updated: 2024/01/23 20:07:12 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLST_INTERN_H
# define FT_DLST_INTERN_H

# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <string.h>

# include "ft_dlst.h"

t_dlst_stat	add_all_to_empty(t_dlst *list1, t_dlst *list2);
bool		link_all_externally(t_dlst *list, t_dnode **h, t_dnode **t);
void		splice_between(t_dlst *l1, t_dlst *l2, t_dnode *left,
				t_dnode *right);
void		link_behind(t_dnode *const base, t_dnode *ins);
void		link_after(t_dnode *base, t_dnode *ins);
void		swap(t_dnode *n1, t_dnode *n2);
void		swap_adjacent(t_dnode *n1, t_dnode *n2);
void		*unlink(t_dlst *list, t_dnode *node);
bool		unlink_all(t_dlst *list, void (*cb) (void*));
t_dlst_stat	get_node_at(t_dlst *list, size_t index, t_dnode **out);
t_dnode		*get_node(t_dlst *list, void *element);

#endif

// TODO comprobar cambios de las funciones intern
// TODO algunas funcion que devuelven con status han
//		sido cambiada comprobar el return
