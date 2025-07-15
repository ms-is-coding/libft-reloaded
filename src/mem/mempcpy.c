/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mempcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:41:42 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/15 11:00:41 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_mempcpy(void *dst, const void *src, size_t n)
{
	auto const char *src_ = src;
	auto char *dst_ = dst;
	while (n--)
		*(unsigned char *)dst_++ = *(unsigned char *)src_++;
	return (dst_);
}
