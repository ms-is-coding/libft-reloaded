/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:26:54 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/18 08:41:17 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_result	ft_file_init(t_file *file, int fd)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, file->buf, FILE_BUFFER_SIZE);
	if (bytes_read < 0)
		return (RESULT_READ_ERROR);
	file->fd = fd;
	file->len = (unsigned int)bytes_read;
	file->curr = file->buf;
	file->line = 1;
	file->eof = false;
	return (RESULT_OK);
}

static inline _Bool	ft_file_can_advance(t_file *file)
{
	return (file->curr + 1 < file->buf + file->len);
}

static inline _Bool	ft_file_has_data(t_file *file)
{
	return (file->curr < file->buf + file->len);
}

static t_result	ft_file_fill(t_file *file)
{
	ssize_t	bytes_read;
	size_t	remaining;

	if (file->curr > file->buf)
	{
		remaining = (size_t)(file->len - (size_t)(file->curr - file->buf));
		ft_memmove(file->buf, file->curr, remaining);
		file->curr = file->buf;
		file->len = (unsigned int)remaining;
	}
	bytes_read = read(file->fd, file->buf + file->len,
			FILE_BUFFER_SIZE - file->len);
	if (bytes_read < 0)
		return (RESULT_ERROR);
	if (bytes_read == 0)
	{
		file->eof = true;
		return (RESULT_EOF);
	}
	file->len += bytes_read;
	return (RESULT_OK);
}

static t_result	ft_file_advance(t_file *file)
{
	t_result	result;

	if (!ft_file_can_advance(file))
	{
		result = ft_file_fill(file);
		if (result != RESULT_OK)
			return (result);
	}
	if (*file->curr == '\n')
		file->line++;
	file->curr++;
	return (RESULT_OK);
}

static t_result	ft_file_skip_whitespace(t_file *file)
{
	t_result	result;

	while (true)
	{
		if (ft_isspace(*file->curr))
			result = ft_file_advance(file);
		else
			break;
		if (result != RESULT_OK)
			return (result);
	}
	return (RESULT_OK);
}

_Bool	ft_file_eof(t_file *file)
{
	if (file->eof)
		return (true);
	if (file->curr == file->buf && file->len == 0)
		file->eof = true;
	return (file->eof);
}

t_result	try(t_result res)
{
	return (res);
}

t_result	ft_file_atoi32(t_file *file, int32_t *ret_ptr)
{
	int			sign;
	_Bool		had_digit;
	t_result	result;

	ft_printf("Called %s\n", __func__);
	if (ft_file_eof(file))
		return (RESULT_EOF);
	*ret_ptr = 0;
	sign = 1;
	result = try(ft_file_skip_whitespace(file));
	if (result != RESULT_OK)
		return (result);
	if (ft_file_has_data(file) && *file->curr == '-')
	{
		sign = -1;
		if (ft_file_advance(file))
			return (RESULT_ERROR);
	}
	else if (ft_file_has_data(file) && *file->curr == '+')
		if (ft_file_advance(file) != RESULT_OK)
			return (RESULT_ERROR);
	had_digit = false;
	while (ft_file_has_data(file) && ft_isdigit(*file->curr))
	{
		int digit = *file->curr - '0';
		if (*ret_ptr > (INT_MAX - digit) / 10)
			return (RESULT_OVERFLOW);
		*ret_ptr = *ret_ptr * 10 + digit;
		if (ft_file_advance(file) != RESULT_OK)
			return (RESULT_ERROR);
		had_digit = true;
	}
	if (!had_digit)
		return (RESULT_INVAL);
	*ret_ptr = sign * *ret_ptr;
	ft_file_skip_whitespace(file);
	return (RESULT_OK);
}

t_result	ft_file_consume(t_file *file, char c, _Bool *found)
{
	t_result	r;

	if (ft_file_eof(file))
		return (RESULT_EOF);
	*found = false;
	if (ft_file_has_data(file) && *file->curr == c)
	{
		r = ft_file_advance(file);
		if (r != RESULT_OK)
			return (r);
		*found = true;
	}
	return (RESULT_OK);
}

