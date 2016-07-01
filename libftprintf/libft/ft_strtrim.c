/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:07:51 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:13:17 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && i < j)
		j--;
	str = ft_strsub(s, i, j - i + 1);
	return (str);
}
