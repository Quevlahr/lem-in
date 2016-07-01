/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:22:17 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/10 15:32:44 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			ft_putnbr_ul(unsigned long nb)
{
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr_ul(nb / 10);
		ft_putnbr_ul(nb % 10);
	}
}
