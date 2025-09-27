/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:27:49 by smamalig          #+#    #+#             */
/*   Updated: 2025/09/27 23:19:49 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdint.h>

#if defined (__AVX512F__)
# include <immintrin.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	uint8_t	*dst;
	__m512i	v;

	i = 0;
	dst = (uint8_t *)s;
	v = _mm512_set1_epi8((char)c);
	while ((i < n) && ((uintptr_t)(dst + i) & 63))
		dst[i++] = (uint8_t)c;
	while (i + 64 <= n)
	{
		_mm512_storeu_si512((__m512i *)(dst + i), v);
		i += 64;
	}
	while (i < n)
		dst[i++] = (uint8_t)c;
	return (s);
}
#else

void	*ft_memset(void *s, int c, size_t n)
{
	const uintptr_t	mask = 0x0101010101010101ULL * (uint8_t)c;
	const size_t	align_mask = sizeof(uintptr_t) - 1;
	uint8_t			*dst;
	size_t			i;

	i = 0;
	dst = (uint8_t *)s;
	while ((uintptr_t)(dst + i) & align_mask && i < n)
		dst[i++] = (uint8_t)c;
	while (i + sizeof(uintptr_t) <= n)
	{
		*(uintptr_t *)(dst + i) = mask;
		i += sizeof(uintptr_t);
	}
	while (i < n)
		dst[i++] = (uint8_t)c;
	return (s);
}

#endif
