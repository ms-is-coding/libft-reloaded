/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:43:48 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/11 22:14:00 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_subs(const char *s, char delim)
{
	int	count;
	int	set;

	count = 0;
	set = 1;
	if (!s)
		return (1);
	while (*s)
	{
		if (set && *s == delim)
		{
			count++;
			set = 0;
		}
		else if (*s != delim)
			set = 1;
		s++;
	}
	return (count + 1);
}

static void	ft_split_inner(const char *s, char delim, char **retval)
{
	int		set;
	char	*start;

	set = 0;
	start = (char *)s;
	while (*s)
	{
		if (*s == delim)
		{
			if (set)
				*retval++ = ft_substr(start, 0, s - start);
			set = 0;
			start = (char *)s + 1;
		}
		if (*s != delim)
			set = 1;
		s++;
	}
	if (set)
		*retval++ = ft_substr(start, 0, s - start);
	*retval = 0;
}

char	**ft_split(const char *s, char delim)
{
	char	**retval;

	retval = malloc(sizeof(char *) * count_subs(s, delim));
	if (!retval)
		return (NULL);
	if (!s)
		return (retval);
	ft_split_inner(s, delim, retval);
	return (retval);
}
