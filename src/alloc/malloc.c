/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:13:39 by smamalig          #+#    #+#             */
/*   Updated: 2025/11/21 17:11:37 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size)
{
	size_t	*ptr;

	ptr = malloc(size + sizeof(size_t));
	if (!ptr)
		return (NULL);
	ptr[0] = size;
	return (&ptr[1]);
}
