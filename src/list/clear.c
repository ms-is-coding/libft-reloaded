/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:47:59 by smamalig          #+#    #+#             */
/*   Updated: 2025/10/28 22:59:24 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list **ptr, void (*del)(t_value))
{
	t_list	*temp;

	if (!ptr)
		return ;
	while (*ptr)
	{
		temp = *ptr;
		*ptr = temp->next;
		if (temp->data.type != TYPE_UNDEFINED)
			del(temp->data);
		free(temp);
	}
}
