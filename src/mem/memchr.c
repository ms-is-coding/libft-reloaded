/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:32:01 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/15 10:59:41 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*s_ = s;

	while (n--)
	{
		if (*(unsigned char *)s_ == (unsigned char)c)
			return ((void *)s_);
		s_++;
	}
	return (NULL);
}
