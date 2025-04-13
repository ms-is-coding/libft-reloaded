/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:45:37 by smamalig          #+#    #+#             */
/*   Updated: 2025/04/14 00:44:09 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define PHI 0x9e3779b9

t_rng	ft_rng_init(t_u32 seed)
{
	return ((t_rng){
		.state = {
			0xdeadbeef ^ seed,
			0x12345678 ^ (seed * PHI),
			0x87654321 ^ (~seed),
			seed ^ (seed >> 16)
		},
		.seed = seed,
		.hash = 0
	});
}

t_u32	ft_rng_next(t_rng *r)
{
	t_u32	result;

	result = r->state[0] ^ (r->state[1] << 11) ^ (r->state[2] >> 7)
		^ (r->state[3] << 3) ^ (r->hash += PHI) ^ r->seed;
	result ^= result << 13;
	result ^= result >> 17;
	result ^= result << 5;
	r->state[0] = r->state[1];
	r->state[1] = r->state[2];
	r->state[2] = r->state[3];
	r->state[3] = result;
	return (result);
}
