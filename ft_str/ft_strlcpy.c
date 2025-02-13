/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:16:48 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/12 18:02:57 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *d, const char *src, size_t dsize)
{
	const char	*s;
	size_t		n;

	n = dsize;
	s = src;
	if (n > 0)
	{
		while (--n > 0)
		{
			*d++ = *s;
			if (!*s++)
				break ;
		}
	}
	if (n == 0)
	{
		if (dsize > 0)
			*d = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}
