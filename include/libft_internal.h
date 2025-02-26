/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:23:28 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/25 16:25:11 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INTERNAL_H
# define LIBFT_INTERNAL_H

#include <stdarg.h>
#include <stddef.h>

typedef enum e_printf_parse_state
{
	PARSE_NORMAL
}	t_printf_parse_state;

typedef struct s_printf_parser
{
	char		*dst;
	const char	*fmt;
	va_list		ap;
	size_t		size;
}	t_printf_parser;

#endif
