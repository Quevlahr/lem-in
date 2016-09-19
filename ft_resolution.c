/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 19:08:06 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/19 11:35:50 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_solve(t_room *start, t_room *end)
{
	int			i;

	i = 0;
	// start = start->doors[i];
	start->pass = 1;
	while (start->doors[i])
	{
		if (start->doors[i]->id == 1)
			return (1);
		i++;
	}
	i = 0;
	while (start->doors[i])
	{
		if (start->doors[i]->pass == 0)
		{
			ft_printf("salle : %s\n", start->name);
			if (ft_solve(start->doors[i], end))
				return (1);
		}
		i++;
	}
	return (0);
}

// int				ft_resolution(t_room *start, t_room *end)
// {
// 	int			i;

// 	i = 0;
// 	while (start->id != 1)
// 	{
// 		if (ft_verif(start, end, i) == 0)

// 		else
// 		{
// 			start->doors[]
// 		}
// 	}
// 	return (0);
// }