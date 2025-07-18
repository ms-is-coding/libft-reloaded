/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitespace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 08:44:07 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/18 10:17:29 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_result	_ft_file_skip_whitespace(t_file *file)
{
	t_result	result;

	while (true)
	{
		if (ft_isspace(*file->curr))
			result = _ft_file_advance(file);
		else
			break ;
		if (result != RESULT_OK)
			return (result);
	}
	return (RESULT_OK);
}
