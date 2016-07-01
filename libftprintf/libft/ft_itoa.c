/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:12:01 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:12:28 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*remp(int nb, int *i, char *tmp, char s)
{
	while (nb > 9)
	{
		tmp[*i] = (nb % 10) + '0';
		nb /= 10;
		*i += 1;
	}
	tmp[*i] = (nb % 10) + '0';
	*i += 1;
	if (s == '-')
	{
		tmp[*i] = '-';
		*i += 1;
	}
	tmp[*i] = '\0';
	*i -= 1;
	return (tmp);
}

static char		*decompose(int nb)
{
	char	s;
	int		i;
	int		j;
	char	*tmp;
	char	*tab;

	i = 0;
	j = 0;
	s = '+';
	(nb < 0) ? s = '-' : 0;
	(nb < 0) ? nb *= -1 : 0;
	(nb < 0) ? j++ : 0;
	tmp = (char*)malloc(sizeof(char) * (ft_nbrlen(nb) + j + 1));
	tab = (char*)malloc(sizeof(char) * (ft_nbrlen(nb) + j + 1));
	tmp = remp(nb, &i, tmp, s);
	j = 0;
	while (i >= 0)
	{
		tab[j] = tmp[i];
		i--;
		j++;
	}
	tab[j] = '\0';
	free(tmp);
	return (tab);
}

char			*ft_itoa(int n)
{
	char	*tab;
	int		b;

	b = 0;
	if (n == -2147483648)
	{
		n = -2147483647;
		b = 1;
	}
	tab = decompose(n);
	if (b == 1)
		tab[ft_strlen(tab) - 1] = '8';
	return (tab);
}
