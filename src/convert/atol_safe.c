/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol_safe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:13:22 by smamalig          #+#    #+#             */
/*   Updated: 2025/03/17 23:39:45 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <limits.h>

#define UPPER_DIGIT 7
#define LOWER_DIGIT 8

long	ft_atol_safe(const char *s)
{
	long	value;
	int		sign;

	value = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		sign = 44 - *s++;
	while (ft_isdigit(*s) && errno != ERANGE)
	{
		value = value * 10 + *s++ - '0';
		if (ft_isdigit(*s) && (value > LONG_MAX / 10
				|| (sign == 1 && value == LONG_MAX / 10
					&& *s - '0' > UPPER_DIGIT)
				|| (sign == -1 && value == LONG_MAX / 10
					&& *s - '0' > LOWER_DIGIT)))
			errno = ERANGE;
	}
	if (errno == ERANGE && sign == 1)
		return (LONG_MAX);
	else if (errno == ERANGE)
		return (LONG_MIN);
	return (sign * value);
}
