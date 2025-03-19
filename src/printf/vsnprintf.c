/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsnprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:31:49 by smamalig          #+#    #+#             */
/*   Updated: 2025/03/19 15:24:47 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"
#include "libft.h"
#include <string.h>
#include <errno.h>
#include <stdio.h>

void	ft_insert(t_printf_parser *parser, char c)
{
	if (parser->size > 1)
		*parser->dst = c;
	else if (parser->size == 1)
		*parser->dst = 0;
	parser->dst++;
	if (parser->size)
		parser->size--;
}

void	ft_print_string(t_printf_parser *parser, const char *str)
{
	while (*str)
		ft_insert(parser, *str++);
}

void	ft_print_int(t_printf_parser *parser, int n)
{
	if (n < 0)
		ft_insert(parser, '-');
	if (n >= 10 || n <= -10)
		ft_print_int(parser, ft_abs(n / 10));
	ft_insert(parser, ft_abs(n % 10) + '0');
}

void	ft_print_strerror(t_printf_parser *parser)
{
	const char	*err = strerror(errno);

	while (*err)
		ft_insert(parser, *err++);
}

void	ft_handle_conversion(t_printf_parser *parser)
{
	if (*parser->fmt == 's')
		ft_print_string(parser, va_arg(parser->ap, const char *));
	else if (*parser->fmt == 'd' || *parser->fmt == 'i')
		ft_print_int(parser, va_arg(parser->ap, int));
	else if (*parser->fmt == 'c')
		ft_insert(parser, va_arg(parser->ap, int));
	else if (*parser->fmt == 'm')
		ft_print_strerror(parser);
	else
		return (ft_insert(parser, '%'));
	parser->fmt++;
}

int	ft_vsnprintf(char *dst, size_t size, const char *fmt, va_list ap)
{
	t_printf_parser	parser;

	parser.dst = dst;
	parser.fmt = fmt;
	parser.size = size;
	va_copy(parser.ap, ap);
	while (*parser.fmt)
	{
		while (*parser.fmt && *parser.fmt != '%')
			ft_insert(&parser, *parser.fmt++);
		if (!*parser.fmt)
			break ;
		parser.fmt++;
		if (*parser.fmt == '%')
			ft_insert(&parser, *parser.fmt++);
		else
			ft_handle_conversion(&parser);
	}
	if (parser.size)
		*parser.dst = 0;
	va_end(parser.ap);
	return (parser.dst - dst);
}
