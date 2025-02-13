/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:41:42 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/12 18:02:23 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_mempcpy(void *dst, const void *src, size_t n)
{
	while (n-- > 0)
		*((unsigned char *)dst++) = *((unsigned char *)src++);
	return (dst);
}
