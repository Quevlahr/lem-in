/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:20:49 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:12:43 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	void		*tmp;

	tmp = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (((unsigned char*)tmp)[i] == (unsigned char)c)
			return (&tmp[i]);
		i++;
	}
	return (NULL);
}
