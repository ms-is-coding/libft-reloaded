/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:13:26 by smamalig          #+#    #+#             */
/*   Updated: 2025/03/24 22:27:39 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/syscall.h>

static void	__ft_sleep(const struct timespec *t)
{
	asm volatile (
		"syscall"
		:
		: "a"(SYS_nanosleep), "D"(t), "S"(0)
		: "rcx", "r11", "memory");
}

int	ft_usleep(__useconds_t us)
{
	const struct timespec	t = {
		.tv_sec = us / 1000000,
		.tv_nsec = (us % 1000000) * 1000
	};

	__ft_sleep(&t);
	return (0);
}

int	ft_sleep(unsigned int seconds)
{
	const struct timespec	t = {
		.tv_sec = seconds,
		.tv_nsec = 0
	};

	__ft_sleep(&t);
	return (0);
}
