/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 16:01:51 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:12:40 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_lstsize(t_list *begin)
{
	t_list		*list;
	int			i;

	list = begin;
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
