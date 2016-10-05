/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 19:08:06 by quroulon          #+#    #+#             */
/*   Updated: 2016/10/05 18:36:58 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_solve(t_lem_in *env, t_room *start, int *nb)
{
	int			i;
	int			tmp = 1;

	i = 0;
	start->pass = 1;
	while (start->doors[i])
	{
		if (start->doors[i]->id == 1)
		{
			(*nb)++;
			start->pass = 0;
			if (start->id == 0)
				start->path = start->doors[i];
			else
				start->tmp_path = start->doors[i];
			return (1);
		}
		i++;
	}
	i = 0;
	while (start->doors[i])
	{
		if (start->doors[i]->pass == 0)
		{
			start->tmp_path = start->doors[i];
			(*nb)++;
			if ((*nb) < env->tmp && (tmp = ft_solve(env, start->doors[i], nb)))
			{
				env->tmp = *nb;
				(*nb) -= 2;
				env->room = env->start;
				while (env->room)
				{
					env->room->path = env->room->tmp_path;
					if (!env->room->path)
						break ;
					env->room = env->room->tmp_path;
				}
			}
			if ((*nb) >= env->tmp)
				(*nb)--;
		}
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
	ft_solve(env, env->start, &nb);
	// ft_printf("name : %s\n", env->end->name);
	env->room = env->start;
	while (env->room)
	{
		ft_printf("path : %s\n", env->room->name);
		if (env->room->path == NULL)
			break ;
		env->room = env->room->path;
	}
	if (env->room->id != env->end->id)
		ft_error_lem_in("Il n'y pas de chemin vers la fin", env);

	return (0);
}
