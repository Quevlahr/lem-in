/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:25:24 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:12:37 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
	}
	else if (list)
	{
		if (!(list->content = malloc(content_size + 1)))
			return (NULL);
		ft_memmove(list->content, content, content_size);
		list->content_size = content_size;
		list->next = NULL;
	}
	return (list);
}
