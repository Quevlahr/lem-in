/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:50:38 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:13:11 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while ((s1[i] || s2[i]) && j < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
		i++;
		j++;
	}
	return (0);
}
