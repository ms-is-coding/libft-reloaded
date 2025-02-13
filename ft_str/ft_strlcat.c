/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:55:37 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/12 18:02:53 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	src_sz;
	size_t	dst_sz;

	src_sz = ft_strlen(src);
	dst_sz = ft_strlen(dst);
	if (dsize <= dst_sz)
		return (dsize + src_sz);
	dst += dst_sz;
	while (*src && dst_sz < --dsize)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_sz + src_sz);
}
