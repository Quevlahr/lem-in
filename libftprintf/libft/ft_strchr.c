/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:33:46 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:12:55 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;

	a = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			return (&((char*)s)[i]);
		i++;
	}
	if (s[i] == a)
		return (&((char*)s)[i]);
	return (NULL);
}
