/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 20:14:56 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/24 15:28:12 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				ft_wstrlen(wchar_t *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] < 128)
			res++;
		else if (str[i] < 2048)
			res += 2;
		else if (str[i] < 65536)
			res += 3;
		else
			res += 4;
		i++;
	}
	return (res);
}
