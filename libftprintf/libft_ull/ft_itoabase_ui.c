/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase_ui.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 18:40:34 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/06 18:40:46 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_convert(unsigned int n, char *str, unsigned int base, int *i)
{
	if (n < base)
	{
		str[*i] = (n > 9 ? n + '7' : n + '0');
		*i += 1;
	}
	else
	{
		ft_convert(n / base, str, base, i);
		ft_convert(n % base, str, base, i);
	}
}

static int		ft_len_itoa(unsigned int n, int base)
{
	int			len;

	len = 0;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char			*ft_itoabase_ui(unsigned int n, int base, int maj)
{
	char		*str;
	int			i;

	i = 0;
	str = ft_strnew(ft_len_itoa(n, base) + 1);
	ft_convert(n, str, base, &i);
	i = 0;
	if (maj == 0)
		while (i < (int)ft_strlen(str))
		{
			(str[i] > '9' ? str[i] += 'W' - '7' : 0);
			i++;
		}
	return (str);
}
