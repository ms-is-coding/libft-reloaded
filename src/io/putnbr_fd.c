/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:53:48 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/23 12:29:23 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[12];
	int		i;

	i = ft_intlen(n);
	buf[i--] = 0;
	if (n < 0)
		buf[0] = '-';
	if (n == 0)
		buf[0] = '0';
	while (n)
	{
		buf[i--] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	write(fd, buf, ft_strlen(buf));
}
