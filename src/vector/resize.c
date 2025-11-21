/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:10:27 by smamalig          #+#    #+#             */
/*   Updated: 2025/11/21 17:19:01 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stddef.h>

t_result	ft_vector_resize(t_vector *vec, size_t size)
{
	t_value	*save_ptr;
	t_value	*new_data;
	size_t	real_offset;

	if (size <= vec->capacity)
		return (RESULT_ERROR);
	new_data = ft_realloc(vec->data, size * sizeof(t_value));
	if (!new_data)
		return (RESULT_ERROR);
	real_offset = vec->offset % vec->capacity;
	save_ptr = ft_mempcpy(new_data, vec->data + real_offset,
			sizeof(t_value) * (vec->capacity - real_offset));
	ft_mempcpy(save_ptr, vec->data, sizeof(t_value) * real_offset);
	ft_free(vec->data);
	vec->data = new_data;
	vec->capacity = size;
	vec->offset = 0;
	return (RESULT_OK);
}
