/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:58:19 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/22 22:18:38 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n-- && *(unsigned char *)src != c)
		*((unsigned char *)dst++) = *((unsigned char *)src++);
	if (n)
		*((unsigned char *)dst++) = c;
	else
		return (0);
	return (dst);
}
