/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:11:22 by pedro             #+#    #+#             */
/*   Updated: 2024/04/07 15:51:59 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLST_H
# define FT_DLST_H

# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <string.h>

typedef enum e_list_stat
{
	LST_OK = 0,
	LST_ERR_ALLOC = 1,
	LST_ERR_INVALID_CAPACITY = 2,
	LST_ERR_INVALID_RANGE = 3,
	LST_ERR_MAX_CAPACITY = 4,
	LST_ERR_KEY_NOT_FOUND = 6,
	LST_ERR_VALUE_NOT_FOUND = 7,
	LST_ERR_OUT_OF_RANGE = 8,
	LST_ITER_END = 9,
}	t_dlst_stat;

typedef struct s_dnode
{
	void			*data;
	struct s_dnode	*next;
	struct s_dnode	*prev;
}	t_dnode;

typedef struct s_dlst
{
	size_t	size;
	t_dnode	*head;
	t_dnode	*tail;

	void	*(*mem_alloc)(size_t size);
	void	*(*mem_calloc)(size_t blocks, size_t size);
	void	(*mem_free)(void *block);
}	t_dlst;

typedef struct s_list_iter
{
	size_t	index;
	t_dlst	*list;
	t_dnode	*last;
	t_dnode	*next;
}	t_dlst_iter;

typedef struct s_dlst_zip
{
	t_dlst	*l1;
	t_dlst	*l2;
	t_dnode	*l1_last;
	t_dnode	*l2_last;
	t_dnode	*l1_next;
	t_dnode	*l2_next;
	size_t	index;
}	t_dlst_zip;

typedef struct s_list_conf
{
	void	*(*mem_alloc)(size_t size);
	void	*(*mem_calloc)(size_t blocks, size_t size);
	void	(*mem_free)(void *block);
}	t_dlst_conf;

void		ft_dlst_conf_init(t_dlst_conf *conf);
t_dlst_stat	ft_dlst_new(t_dlst **list);
t_dlst_stat	ft_dlst_new_conf(t_dlst_conf const *const conf, t_dlst **list);
void		ft_dlst_destroy(t_dlst *list);
void		ft_dlst_destroy_cb(t_dlst *list, void (*cb) (void*));

t_dlst_stat	ft_dlst_splice(t_dlst *list1, t_dlst *list2);
t_dlst_stat	ft_dlst_splice_at(t_dlst *list, t_dlst *list2, size_t index);

t_dlst_stat	ft_dlst_add(t_dlst *list, void *element);
t_dlst_stat	ft_dlst_add_at(t_dlst *list, void *element, size_t index);
t_dlst_stat	ft_dlst_add_all(t_dlst *list1, t_dlst *list2);
t_dlst_stat	ft_dlst_add_all_at(t_dlst *list, t_dlst *list2, size_t index);
t_dlst_stat	ft_dlst_add_first(t_dlst *list, void *element);
t_dlst_stat	ft_dlst_add_last(t_dlst *list, void *element);

t_dlst_stat	ft_dlst_remove(t_dlst *list, void *element, void **out);
t_dlst_stat	ft_dlst_remove_first(t_dlst *list, void **out);
t_dlst_stat	ft_dlst_remove_last(t_dlst *list, void **out);
t_dlst_stat	ft_dlst_remove_at(t_dlst *list, size_t index, void **out);

t_dlst_stat	ft_dlst_remove_all(t_dlst *list);
t_dlst_stat	ft_dlst_remove_all_cb(t_dlst *list, void (*cb) (void*));

t_dlst_stat	ft_dlst_get_at(t_dlst *list, size_t index, void **out);
t_dlst_stat	ft_dlst_get_first(t_dlst *list, void **out);
t_dlst_stat	ft_dlst_get_last(t_dlst *list, void **out);

t_dlst_stat	ft_dlst_sublist(t_dlst *list, size_t from, size_t to, t_dlst **out);
t_dlst_stat	ft_dlst_copy_shallow(t_dlst *list, t_dlst **out);
t_dlst_stat	ft_dlst_copy_deep(t_dlst *list, void *(*cp) (void*), t_dlst **out);

t_dlst_stat	ft_dlst_replace_at(t_dlst *list, void *element,
				size_t index, void **out);

size_t		ft_dlst_contains(t_dlst *list, void *element);
size_t		ft_dlst_contains_value(t_dlst *list, void *element,
				int (*cmp) (const void*, const void*));
t_dlst_stat	ft_dlst_index_of(t_dlst *list, void *element,
				int (*cmp) (const void*, const void*), size_t *index);
t_dlst_stat	ft_dlst_to_array(t_dlst *list, void ***out);

void		ft_dlst_reverse(t_dlst *list);
t_dlst_stat	ft_dlst_sort(t_dlst *list, int (*cmp) (void const*, void const*));
size_t		ft_dlst_size(t_dlst *list);

void		ft_dlst_foreach(t_dlst *list, void (*op) (void *));

t_dlst_stat	ft_dlst_reduce(t_dlst *list,
				void (*fn)(void *, void *, void *), void *result);

t_dlst_stat	ft_dlst_filter_mut(t_dlst *list, bool (*predicate) (const void*));
t_dlst_stat	ft_dlst_filter(t_dlst *list,
				bool (*predicate) (const void*), t_dlst **out);

void		ft_dlst_iter_init(t_dlst_iter *iter, t_dlst *list);
t_dlst_stat	ft_dlst_iter_remove(t_dlst_iter *iter, void **out);
t_dlst_stat	ft_dlst_iter_add(t_dlst_iter *iter, void *element);
t_dlst_stat	ft_dlst_iter_replace(t_dlst_iter *iter, void *element, void **out);
size_t		ft_dlst_iter_index(t_dlst_iter *iter);
t_dlst_stat	ft_dlst_iter_next(t_dlst_iter *iter, void **out);

void		ft_dlst_diter_init(t_dlst_iter *iter, t_dlst *list);
t_dlst_stat	ft_dlst_diter_remove(t_dlst_iter *iter, void **out);
t_dlst_stat	ft_dlst_diter_add(t_dlst_iter *iter, void *element);
t_dlst_stat	ft_dlst_diter_replace(t_dlst_iter *iter, void *element, void **out);
size_t		ft_dlst_diter_index(t_dlst_iter *iter);
t_dlst_stat	ft_dlst_diter_next(t_dlst_iter *iter, void **out);

void		ft_dlst_zip_init(t_dlst_zip *iter, t_dlst *l1, t_dlst *l2);
t_dlst_stat	ft_dlst_zip_next(t_dlst_zip *iter, void **out1, void **out2);
t_dlst_stat	ft_dlst_zip_add(t_dlst_zip *iter, void *e1, void *e2);
t_dlst_stat	ft_dlst_zip_remove(t_dlst_zip *iter, void **out1, void **out2);
t_dlst_stat	ft_dlst_zip_replace(t_dlst_zip *iter,
				void **e, void **out1, void **out2);
size_t		ft_dlst_zip_index(t_dlst_zip *iter);

#endif
