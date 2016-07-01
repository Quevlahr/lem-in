/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 20:28:51 by quroulon          #+#    #+#             */
/*   Updated: 2016/05/10 20:30:40 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			ft_putnbr_ui(unsigned int nb)
{
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr_ui(nb / 10);
		ft_putnbr_ui(nb % 10);
	}
}
