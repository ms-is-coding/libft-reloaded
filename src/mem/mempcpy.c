/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mempcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:41:42 by smamalig          #+#    #+#             */
/*   Updated: 2025/10/06 02:08:54 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magic.h"
#include "libft.h"
#include <stdint.h>

void	*ft_mempcpy(void *dst, const void *src, size_t n)
{
	const uint8_t	*s;
	uint8_t			*d;
	size_t			i;

	s = src;
	d = dst;
	i = 0;
	while ((ptrdiff_t)(d + i) & ALIGN_MASK && i < n)
	{
		d[i] = s[i];
		i++;
	}
	while (i + sizeof(uintptr_t) < n)
	{
		*(uintptr_t *)(void *)(d + i)
			= *(const uintptr_t *)(const void *)(s + i);
		i += sizeof(uintptr_t);
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d + i);
}
