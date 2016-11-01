/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 19:08:06 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/01 15:06:26 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_find_path(t_lem_in *env, t_room *room, int *nb)
{
	int			i;

	i = 0;
	if (room->id == 1)
		return (1);
	while (room->doors[i])
	{
		if (room->pds - 1 == room->doors[i]->pds && room->doors[i]->pass == 0)
		{
			(*nb)++;
			room->path = room->doors[i];
			room->pass = 1;
			if (ft_find_path(env, room->doors[i], nb) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

void			ft_solve(t_lem_in *env, t_room *room)
{
	int			i;
	t_room		*tmp;

	i = 0;
	if (room->id == 0)
		env->tmp = room->pds;
	room->pass = 1;
	while (room->doors[i])
	{
		tmp = room->doors[i];
		if (tmp->pds > room->pds + 1)//  && room->doors[i]->id != 0)
		{
			tmp->pds = room->pds + 1;
			ft_solve(env, room->doors[i]);
		}
		else if (tmp->pds == 0)
			tmp->pds = room->pds + 1;
		i++;
	}
	i = 0;
	while (room->doors[i])
	{
		env->room = room;
		if ((env->tmp == 0 || env->tmp > room->pds + 1) && room->doors[i]->pass == 0)
			ft_solve(env, room->doors[i]);
		i++;
	}
	return ;
}

int				ft_resolution(t_lem_in *env)
{
	int			nb;

	env->end->pds = 1;
	env->tmp = 0;
	nb = 0;
	ft_solve(env, env->end);
	env->room = env->start->begin;
	while (env->room)
	{
		env->room->pass = 0;
		if (env->room->next == NULL)
			break ;
		env->room = env->room->next;
	}
	ft_find_path(env, env->start, &nb);
	nb = 0;
	env->room = env->start;
	while (env->room)
	{
		nb++;
		if (env->room->path == NULL)
			break ;
		env->room = env->room->path;
	}
	if (env->room->id != env->end->id)
		ft_error_lem_in(NULL, env);
		// ft_error_lem_in("Il n'y pas de chemin vers la fin", env);
	env->nb_path = nb;
	return (0);
}
