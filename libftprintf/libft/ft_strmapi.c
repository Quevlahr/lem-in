/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 20:03:05 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:13:09 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	if (s && f)
	{
		i = ft_strlen((char*)s);
		if (!(str = (char*)malloc(sizeof(str) * (i + 1))))
			return (NULL);
		while (s[j])
		{
			str[j] = f(j, s[j]);
			j++;
		}
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}
