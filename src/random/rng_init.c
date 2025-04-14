/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:46:09 by smamalig          #+#    #+#             */
/*   Updated: 2025/04/14 22:54:54 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_u64	splitmix64(t_u64 *state)
{
	t_u64	x;

	*state += 0x9E3779B97f4A7C15;
	x = *state;
	x = (x ^ (x >> 30)) * 0xBF58476D1CE4E5B9;
	x = (x ^ (x >> 27)) * 0x94D049BB133111EB;
	return (x ^ (x >> 31));
}

void	ft_rng_init(t_rng256 *rng, t_u64 seed)
{
	t_u64	tmp;

	rng->seed = seed;
	tmp = splitmix64(&seed);
	rng->s[0] = (t_u32)tmp;
	rng->s[1] = (t_u32)(tmp >> 32);
	tmp = splitmix64(&seed);
	rng->s[2] = (t_u32)tmp;
	rng->s[3] = (t_u32)(tmp >> 32);
}
