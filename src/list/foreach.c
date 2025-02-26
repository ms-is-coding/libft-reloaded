/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:50:39 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/22 23:37:20 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_foreach(t_list *list, void (*f)(void *))
{
	while (list)
	{
		f(list->data);
		list = list->next;
	}
}
