/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:53:32 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:12:42 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void		*ret;

	if (!(ret = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
