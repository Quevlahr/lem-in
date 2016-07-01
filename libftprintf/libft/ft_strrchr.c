/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:00:18 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:13:15 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	int		i;
	int		max;

	a = (char)c;
	i = 0;
	max = 0;
	while (s[i])
	{
		if (s[i] == a)
			max = i;
		i++;
	}
	if (s[i] == a)
		max = i;
	if ((max != 0 && s != NULL) || (max == 0 && s[0] == a))
		return (&((char*)s)[max]);
	return (NULL);
}
