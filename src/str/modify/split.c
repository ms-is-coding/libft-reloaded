/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:43:48 by smamalig          #+#    #+#             */
/*   Updated: 2025/09/27 22:39:07 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>

static int	alloc_sub(const char *s, const char *start, int i, char **collector)
{
	ptrdiff_t	diff;
	size_t		len;

	if (!collector)
		return (0);
	diff = s - start;
	len = (size_t)diff;
	collector[i] = malloc(len + 1ul);
	if (!collector[i])
		return (1);
	ft_memcpy(collector[i], start, len);
	collector[i][s - start] = 0;
	return (0);
}

static int	split_words(const char *s, char delim, char **collector)
{
	int			count;
	const char	*start;

	count = 0;
	start = NULL;
	while (1)
	{
		if (*s != delim && !start)
			start = s;
		else if (start && (*s == delim || !*s))
		{
			if (alloc_sub(s, start, count, collector))
				return (count);
			count++;
			start = NULL;
		}
		if (!*s)
			break ;
		s++;
	}
	if (collector)
		collector[count] = NULL;
	return (count + 1);
}

char	**ft_split(const char *s, char delim)
{
	char	**collector;
	int		sub_count;
	int		i;

	sub_count = split_words(s, delim, NULL);
	collector = ft_calloc((size_t)sub_count, sizeof(char *));
	if (!collector)
		return (NULL);
	if (split_words(s, delim, collector) != sub_count)
	{
		i = 0;
		while (i < sub_count)
			free(collector[i++]);
		free(collector);
		return (NULL);
	}
	return (collector);
}
