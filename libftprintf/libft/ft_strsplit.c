/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:56:20 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:13:15 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*cut_w(int i, char c, char const *s)
{
	int		j;
	char	*str;

	j = i;
	while (s[j] != c && s[j] != '\0')
		j++;
	str = ft_strsub(s, i, j - i);
	return (str);
}

static int		count_w(char const *s, char c)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0') ||
				(s[i] != c && s[i] != '\0' && i == 0))
			res++;
		i++;
	}
	return (res);
}

static char		**prep_w(char const *s, char c, int nb)
{
	int		res;
	int		i;
	char	**tab;

	res = 0;
	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (nb + 1))))
		return (NULL);
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0') ||
				(s[i] != c && s[i] != '\0' && i == 0))
		{
			(i != 0 || (s[i] == c && i == 0)) ? tab[res] = cut_w(i + 1, c, s) :
				(tab[res] = cut_w(i, c, s));
			res++;
		}
		i++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nb_w;
	char	**tab;

	if (s == NULL)
		return (NULL);
	nb_w = count_w(s, c);
	tab = prep_w(s, c, nb_w);
	tab[nb_w] = NULL;
	return (tab);
}
