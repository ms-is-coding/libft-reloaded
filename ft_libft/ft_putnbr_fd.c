/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:53:48 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/10 21:07:00 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[10];
	int		pos;

	pos = 9;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	else if (n < 0)
		ft_putchar_fd('-', fd);
	while (n)
	{
		if (n < 0)
			buffer[pos--] = -(n % 10) + '0';
		else
			buffer[pos--] = n % 10 + '0';
		n /= 10;
	}
	write(fd, buffer + pos + 1, 9 - pos);
}
