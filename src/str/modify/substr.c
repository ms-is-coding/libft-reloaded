/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:34:37 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/13 18:57:26 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, size_t start, size_t size)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < size && s[start + i])
		res[i] = s[start + i];
	res[i] = 0;
	return (res);
}
