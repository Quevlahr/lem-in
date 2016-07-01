/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttochar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 21:00:16 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:12:41 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_lsttochar(t_list *list, char *str)
{
	while (list)
	{
		str = ft_strncat(str, list->content, list->content_size);
		list = list->next;
	}
	return (str);
}
