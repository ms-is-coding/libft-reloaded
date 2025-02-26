/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:44:30 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/22 23:35:37 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_delete(t_list *el, void (*del)(void *))
{
	if (!el || !del)
		return ;
	if (el->data)
		del(el->data);
	free(el);
}
