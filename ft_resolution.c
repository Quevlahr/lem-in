/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 19:08:06 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/19 18:27:29 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// int				ft_solve(t_lem_in *env, t_room *start, int *nb)
// {
// 	int			i;

// 	i = 0;
// 	start->pass = 1;
// 	while (start->doors[i])
// 	{
// 		if (start->doors[i]->id == 1)
// 			return (1);
// 		i++;
// 	}
// 	i = 0;
// 	while (start->doors[i])
// 	{
// 		if (start->doors[i]->pass == 0)
// 		{
// 			if (ft_solve(env, start->doors[i], nb))
// 				return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int				ft_solve(t_lem_in *env, t_room *start, int *nb)
{
	int			i;

	i = 0;
	ft_printf("room : %s, id : %d, nb : %d.\n", start->name, start->id, *nb);
	start->pass = 1;
	while (start->doors[i])
	{
		if (start->doors[i]->id == 1)
		{
			(*nb)++;
			start->pass = 0;
			ft_printf("room : %s, id : %d, nb : %d.\n", start->doors[i]->name, start->doors[i]->id, *nb);
			return (1);
		}
		i++;
	}
	i = 0;
	while (start->doors[i])
	{
		if (start->doors[i]->pass == 0)
		{
			// ft_printf("saaaaalle : %s\n", start->doors[i]->name);
			(*nb)++;
			if ((*nb) < env->tmp && ft_solve(env, start->doors[i], nb))
			{
				env->tmp = *nb;
				(*nb) -= 2;
				ft_printf("CESTBON\n");
				// return (0);
			}
			if ((*nb) >= env->tmp)
				(*nb)--;
		}
		ft_printf("salle : %s --> %s, nb : %d, pass : %d\n", start->name, start->doors[i]->name, *nb, start->doors[i]->pass);
		i++;

	}
	(*nb)--;
	start->pass = 0;
	return (0);
}

int				ft_resolution(t_lem_in *env)
{
	int			nb;

	nb = 0;
	env->tmp = env->nb_room;
	ft_printf("nb : %d, max : %d\n", nb, env->tmp);
	ft_solve(env, env->start, &nb);
	return (0);
}
