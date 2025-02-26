/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:45:01 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/09 16:18:34 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst <= src || dst >= src + n)
		return (ft_memcpy(dst, src, n));
	dst += n;
	src += n;
	while (n--)
		*(unsigned char *)--dst = *(unsigned char *)--src;
	return (dst);
}
