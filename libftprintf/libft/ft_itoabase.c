/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 20:27:13 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/03 16:12:29 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		puissance(int nb, int psc)
{
	int			i;
	int			res;

	i = 0;
	res = 1;
	while (i < psc)
	{
		res *= nb;
		i++;
	}
	return (res);
}

static char		how_n(int *n, int base, int psc, int maj)
{
	char		c_res;
	int			i_res;
	int			tmp;

	i_res = 1;
	tmp = puissance(base, psc);
	while (*n >= (i_res * tmp))
		i_res++;
	i_res--;
	*n -= i_res * tmp;
	if (maj == 1)
		c_res = (i_res > 9 ? i_res + '7' : i_res + '0');
	else
		c_res = (i_res > 9 ? i_res + 'W' : i_res + '0');
	return (c_res);
}

char			*ft_itoabase(int n, int base, int maj)
{
	int			psc;
	int			res;
	int			i;
	char		*str;

	psc = 0;
	i = 0;
	res = (n < 0) ? -1 : 1;
	n = ft_abs(n);
	if (n == 0 || base < 2)
	{
		str = ft_strnew(1);
		str[0] = '0';
		return (str);
	}
	while (n >= puissance(base, psc))
		psc++;
	psc--;
	str = ft_strnew(psc + 2);
	res == -1 ? str[i++] = '-' : 0;
	while (psc >= 0)
		str[i++] = how_n(&n, base, psc--, maj);
	return (str);
}
