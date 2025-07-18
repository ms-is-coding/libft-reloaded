/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atox32.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 08:39:18 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/18 08:40:51 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_internal.h"

t_result	ft_file_atox32(t_file *file, uint32_t *ret)
{
	t_result	r;

	if (ft_file_eof(file))
		return (RESULT_EOF);
	r = __ft_file_skip_whitespace(file);
	if (r != RESULT_OK)
		return (r);
	*ret = 0;

	return (RESULT_OK);
}

