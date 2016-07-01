/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 16:17:06 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:12:39 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_reverse(t_list **begin)
{
	t_list		*current;
	t_list		*tmp;
	t_list		*tmp2;

	current = *begin;
	tmp2 = NULL;
	while (current)
	{
		tmp = current;
		current = tmp->next;
		tmp->next = tmp2;
		tmp2 = tmp;
	}
	*begin = tmp2;
}
