/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:45:37 by smamalig          #+#    #+#             */
/*   Updated: 2025/03/25 15:47:08 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_rand(unsigned int seed) {
	static int r = 0;

	r += seed + 0xfee1dead;
	r ^= r << 13;
	r ^= r >> 17;
	r ^= r << 5;
	return r & 0x7fffffff;
}
