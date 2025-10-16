/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strspn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:58:36 by smamalig          #+#    #+#             */
/*   Updated: 2025/10/16 18:38:32 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	len;

	len = 0;
	while (s[len] && ft_strchr(accept, s[len]))
		len++;
	return (len);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	len;

	len = 0;
	while (s[len] && !ft_strchr(reject, s[len]))
		len++;
	return (len);
}
