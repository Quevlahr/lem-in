/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:13:02 by quroulon          #+#    #+#             */
/*   Updated: 2016/06/03 16:30:06 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_maxtype(t_env *e)
{
	if (e->flag_ll == 1 || e->flag_l == 1 || e->flag_j == 1 || e->flag_z == 1
		|| e->conv == 'U')
	{
		e->flag_h = 0;
		e->flag_hh = 0;
	}
	else if (e->flag_z == 1)
	{
		e->flag_ll = 0;
		e->flag_l = 0;
		e->flag_j = 0;
	}
	else if (e->flag_h == 1)
		e->flag_hh = 0;
}
