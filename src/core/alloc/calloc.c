/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:52:10 by smamalig          #+#    #+#             */
/*   Updated: 2025/11/25 16:16:44 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/stdlib.h"
#include "core/string.h"
#include <errno.h>

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	if ((size != 0) && (n > SIZE_MAX / size))
	{
		errno = EOVERFLOW;
		return (NULL);
	}
	ptr = ft_malloc(n * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, n * size);
	return (ptr);
}
