/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:37:58 by smamalig          #+#    #+#             */
/*   Updated: 2025/10/30 09:34:50 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// reverse engineering glibc malloc lol
static size_t	ft_usable_size(void *ptr)
{
	size_t	size;
	bool	is_mmapped;

	size = ((size_t *)ptr)[-1];
	is_mmapped = (size & 0x2) >> 1;
	return ((size & ~0x7ul) - (sizeof(size_t) << is_mmapped));
}

// see `man 3p realloc`
void	*ft_realloc(void *ptr, size_t size)
{
	size_t	old_size;
	void	*alloc;

	if (!ptr)
		return (ft_malloc(size));
	if (size == 0)
	{
		ft_free(ptr);
		return (ptr);
	}
	old_size = ft_usable_size(ptr);
	if (size <= old_size)
		return (ptr);
	alloc = ft_malloc(size);
	if (!alloc)
		return (NULL);
	ft_mempcpy(alloc, ptr, old_size);
	ft_free(ptr);
	return (alloc);
}
