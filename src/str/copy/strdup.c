/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:14:50 by smamalig          #+#    #+#             */
/*   Updated: 2025/10/06 02:01:25 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s);
	res = ft_malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	((char *)ft_mempcpy(res, s, len))[0] = 0;
	return (res);
}
