/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:09:08 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/10 21:25:49 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, const char *trim)
{
	size_t	len;
	size_t	i;
	char	*res;

	i = -1;
	while (ft_strchr(trim, *s))
		s++;
	len = ft_strlen(s);
	while (ft_strrchr(trim, s[--len]))
		;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (++i < len + 1)
		res[i] = s[i];
	res[i] = 0;
	return (res);
}
