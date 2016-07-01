/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:18:15 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:13:16 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_strnew(len)) || s == NULL || len > ft_strlen(s))
		return (NULL);
	while ((unsigned long)i < len)
	{
		str[i] = ((char*)s)[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
