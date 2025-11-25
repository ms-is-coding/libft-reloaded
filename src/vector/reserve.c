/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:26:07 by smamalig          #+#    #+#             */
/*   Updated: 2025/11/25 14:27:31 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector_internal.h"
#include "vector/vector.h"
#include <string.h>

t_vec_result	vec_reserve(t_vec *v, size_t capacity)
{
	void	*new_data;

	if (capacity <= v->capacity)
		return (VEC_OK);
	new_data = malloc(capacity * sizeof(void *));
	if (!new_data)
		return (VEC_OOM);
	memcpy(new_data, v->data, v->length * sizeof(void *));
	free(v->data);
	v->data = new_data;
	return (VEC_OK);
}
