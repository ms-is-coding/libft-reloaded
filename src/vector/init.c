/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:38:16 by smamalig          #+#    #+#             */
/*   Updated: 2025/11/21 17:20:35 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_result	ft_vector_init(t_vector *vec, size_t size)
{
	vec->capacity = size;
	vec->length = 0;
	vec->offset = 0;
	vec->data = ft_malloc(size * sizeof(t_value));
	if (!vec->data)
		return (RESULT_ERROR);
	return (RESULT_OK);
}
