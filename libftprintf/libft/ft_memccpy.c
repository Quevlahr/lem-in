/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:14:14 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:12:42 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	void		*ptr;

	ptr = NULL;
	i = 0;
	while (i < n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		if (((char*)src)[i] == c)
			return (&dst[i + 1]);
		i++;
	}
	return (ptr);
}
