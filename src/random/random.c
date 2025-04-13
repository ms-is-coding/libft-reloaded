/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:45:37 by smamalig          #+#    #+#             */
/*   Updated: 2025/04/13 22:55:30 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_random	ft_srand(unsigned int seed)
{
	return ((t_random){
		.data = 0xdeadbeef, .seed = seed
	});
}

t_u32	ft_rand(struct s_random *r)
{
	r->data += r->seed ^ 0x9e3779b9;
	r->data ^= r->data << 13;
	r->data ^= r->data >> 17;
	r->data ^= r->data << 5;
	return (r->data);
}
