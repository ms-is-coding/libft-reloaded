/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:45:37 by smamalig          #+#    #+#             */
/*   Updated: 2025/04/14 22:50:01 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline t_u64	rol64(t_u64 x, int k)
{
	return ((x << k) | (x >> (64 - k)));
}

t_u64	ft_rng_u64(t_rng256 *rng)
{
	t_u64	*s;
	t_u64	x;
	t_u64	t;

	s = rng->s;
	x = rol64(s[0] + s[3], 23) + s[0];
	t = rng->s[1] << 17;
	s[2] ^= s[0];
	s[3] ^= s[1];
	s[1] ^= s[2];
	s[0] ^= s[3];
	s[2] ^= t;
	s[3] = rol64(s[3], 45);
	return (x);
}

t_u32	ft_rng_u32(t_rng256 *rng)
{
	return (ft_rng_u64(rng) >> 32);
}

double	ft_rng_f64(t_rng256 *rng)
{
	return ((ft_rng_u64(rng) >> 11) * (1.0 / 9007199254740992.0));
}
