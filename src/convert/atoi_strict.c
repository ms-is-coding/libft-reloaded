/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_strict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:13:22 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/25 14:16:58 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <limits.h>

#define THRESHOLD INT_MAX / 10
#define UPPER_DIGIT 7
#define LOWER_DIGIT 8

int	ft_atoi_strict(const char *s)
{
	int	value;
	int	sign;
	
	value = 0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		sign = 44 - *s++;
	while (ft_isdigit(*s))
	{
		value = value * 10 + *s++ - '0';
		if (ft_isdigit(*s) && (value > THRESHOLD
			|| (sign == 1 && value == THRESHOLD && *s - '0' > UPPER_DIGIT)
			|| (sign == -1 && value == THRESHOLD && *s - '0' > LOWER_DIGIT)))
		{
			errno = ERANGE;
			return (0);
		}
	}
	return (sign * value);
}
