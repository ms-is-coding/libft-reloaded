/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol_safe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:54:04 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/25 14:18:33 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

#define THRESHOLD LONG_MAX / 10
#define UPPER_DIGIT 7

long	ft_atol_safe(const char *s)
{
	long long	value;
	int	sign;
	int	overflow;
	
	value = 0;
	sign = 1;
	overflow = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		sign = 44 - *s++;
	while (ft_isdigit(*s) && !overflow)
	{
		value = value * 10 + *s++ - '0';
		overflow = ft_isdigit(*s) && (value > THRESHOLD
			|| (value == THRESHOLD && *s - '0' > UPPER_DIGIT));
	}
	if (overflow && sign == 1)
		return INT_MAX;
	else if (overflow)
		return INT_MIN;
	return (sign * value);
}
