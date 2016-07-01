/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:26:18 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:12:34 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*lst;

	temp = *alst;
	while (temp)
	{
		lst = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = lst;
	}
	*alst = NULL;
}
