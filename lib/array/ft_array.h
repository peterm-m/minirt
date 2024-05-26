/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:38:00 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/22 14:45:00 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <string.h>

typedef enum e_arr_stat
{
	ARR_OK = 0,
	ARR_ERR_ALLOC = 1,
	ARR_ERR_INVALID_CAPACITY = 2,
	ARR_ERR_INVALID_RANGE = 3,
	ARR_ERR_MAX_CAPACITY = 4,
	ARR_ERR_KEY_NOT_FOUND = 6,
	ARR_ERR_VALUE_NOT_FOUND = 7,
	ARR_ERR_OUT_OF_RANGE = 8,
	ARR_ITER_END = 9,
}	t_arr_stat;

# define DEFAULT_CAPACITY 8
# define DEFAULT_EXPANSION_FACTOR 2

/**
 * A dynamic array that expands automatically as elements are
 * added. The array supports amortized constant time insertion
 * and removal of elements at the end of the array, as well as
 * constant time access.
 */
typedef struct s_array
{
	size_t	size;
	size_t	capacity;
	float	exp_factor;
	void	**buffer;
	void	*(*mem_alloc)(size_t size);
	void	*(*mem_calloc)(size_t blocks, size_t size);
	void	(*mem_free)(void *block);
}	t_array;

/**
 * Array configuration structure. Used to initialize a new Array
 * with specific values.
 */
typedef struct s_array_conf
{
	size_t				capacity;
	float				exp_factor;

	void				*(*mem_alloc)(size_t size);
	void				*(*mem_calloc)(size_t blocks, size_t size);
	void				(*mem_free)(void *block);
}	t_array_conf;

/**
 * Array iterator structure. Used to iterate over the elements of
 * the array in an ascending order. The iterator also supports
 * operations for safely adding and removing elements during
 * iteration.
 */
typedef struct s_array_iter
{
	t_array	*ar;
	size_t	index;
	bool	last_removed;
}	t_array_iter;

/**
 * Array zip iterator structure. Used to iterate over the elements of two
 * arrays in lockstep in an ascending order until one of the Arrays is
 * exhausted. The iterator also supports operations for safely adding
 * and removing elements during iteration.
 */
typedef struct s_array_zip
{
	t_array	*ar1;
	t_array	*ar2;
	size_t	index;
	bool	last_removed;
}	t_array_zip;

t_arr_stat	ft_array_new(t_array **out);
t_arr_stat	ft_array_new_conf(t_array_conf const *const conf, t_array **out);
void		ft_array_conf_init(t_array_conf *conf);

void		ft_array_destroy(t_array *ar);
void		ft_array_destroy_cb(t_array *ar, void (*cb) (void*));

t_arr_stat	ft_array_add(t_array *ar, void *element);
t_arr_stat	ft_array_add_at(t_array *ar, void *element, size_t index);
t_arr_stat	ft_array_replace_at(t_array *ar, void *element, size_t index,
				void **out);
t_arr_stat	ft_array_swap_at(t_array *ar, size_t index1, size_t index2);

t_arr_stat	ft_array_remove(t_array *ar, void *element, void **out);
t_arr_stat	ft_array_remove_at(t_array *ar, size_t index, void **out);
t_arr_stat	ft_array_remove_last(t_array *ar, void **out);
void		ft_array_remove_all(t_array *ar);
void		ft_array_remove_all_free(t_array *ar);

t_arr_stat	ft_array_get_at(t_array *ar, size_t index, void **out);
t_arr_stat	ft_array_get_last(t_array *ar, void **out);

t_arr_stat	ft_array_subarray(t_array *ar, size_t from, size_t to,
				t_array **out);
t_arr_stat	ft_array_copy_shallow(t_array *ar, t_array **out);
t_arr_stat	ft_array_copy_deep(t_array *ar, void *(*cp) (void*), t_array **out);

void		ft_array_reverse(t_array *ar);
t_arr_stat	ft_array_trim_capacity(t_array *ar);

size_t		ft_array_contains(t_array *ar, void *element);
size_t		ft_array_contains_value(t_array *ar, void *element,
				int (*cmp) (const void*, const void*));
size_t		ft_array_size(t_array *ar);
size_t		ft_array_capacity(t_array *ar);

t_arr_stat	ft_array_index_of(t_array *ar, void *element, size_t *index);
void		ft_array_sort(t_array *ar, int (*cmp) (const void*, const void*));

void		ft_array_map(t_array *ar, void (*fn) (void*));
void		ft_array_reduce(t_array *ar,
				void (*fn)(void*, void*, void*), void *result);

t_arr_stat	ft_array_filter_mut(t_array *ar, bool (*predicate) (const void*));
t_arr_stat	ft_array_filter(t_array *ar, bool (*predicate)(const void*),
				t_array **out);

void		ft_array_iter_init(t_array_iter *iter, t_array *ar);
t_arr_stat	ft_array_iter_next(t_array_iter *iter, void **out);
t_arr_stat	ft_array_iter_remove(t_array_iter *iter, void **out);
t_arr_stat	ft_array_iter_add(t_array_iter *iter, void *element);
t_arr_stat	ft_array_iter_replace(t_array_iter *iter, void *element,
				void **out);
size_t		ft_array_iter_index(t_array_iter *iter);

void		ft_array_zip_init(t_array_zip *iter, t_array *a1, t_array *a2);
t_arr_stat	ft_array_zip_next(t_array_zip *iter, void **out1, void **out2);
t_arr_stat	ft_array_zip_add(t_array_zip *iter, void *e1, void *e2);
t_arr_stat	ft_array_zip_remove(t_array_zip *iter, void **out1, void **out2);
t_arr_stat	ft_array_zip_replace(t_array_zip *iter, void *e1, void *e2,
				void **out[2]);
size_t		ft_array_zip_index(t_array_zip *iter);

void *const	*ft_array_get_buffer(t_array *ar);

#endif
