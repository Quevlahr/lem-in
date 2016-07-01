/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:12:31 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:13:04 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	int		dst_l;
	int		src_l;

	i = 0;
	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	if ((int)size <= dst_l)
		return ((int)size + src_l);
	if ((int)size - dst_l < src_l)
		j = (int)size - dst_l - 1;
	else
		j = src_l;
	while (i < j)
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	dst[dst_l + i] = '\0';
	return (dst_l + i);
}
