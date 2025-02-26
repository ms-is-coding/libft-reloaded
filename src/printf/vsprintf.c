/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:42:14 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/24 15:19:36 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vsprintf(char *dst, const char *fmt, va_list ap)
{
	return (ft_vsnprintf(dst, 0, fmt, ap));
}
