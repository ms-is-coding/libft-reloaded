/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:26:55 by smamalig          #+#    #+#             */
/*   Updated: 2025/11/25 14:26:25 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector_internal.h"
#include "vector/vector.h"

void	*vec_get(const t_vec *v, size_t idx)
{
	if (idx > v->length)
		return (NULL);
	return (v->data[idx]);
}
