/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:16:05 by smamalig          #+#    #+#             */
/*   Updated: 2025/03/24 22:17:36 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <syscall.h>

time_t	ft_time(timer_t *timer)
{
	time_t	result;

	asm volatile (
		"syscall"
		: "=a"(result)
		: "a"(SYS_time), "D"(timer)
		: "rcx", "r11", "memory");
	return (result);
}
