/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:58:19 by smamalig          #+#    #+#             */
/*   Updated: 2025/10/30 11:00:59 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = src;
	d = dst;
	while (n-- && *s != c)
		*(d++) = *(s++);
	if (n)
		*(d++) = (unsigned char)c;
	else
		return (NULL);
	return (d);
}
