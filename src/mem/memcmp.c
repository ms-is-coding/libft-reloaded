/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:38:41 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/15 10:59:54 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s1_ = s1;
	const char	*s2_ = s2;

	while (n--)
	{
		if (*(unsigned char *)s1_ != *(unsigned char *)s2_)
			return (*(unsigned char *)s1_ - *(unsigned char *)s2_);
		s1_++;
		s2_++;
	}
	return (0);
}
