/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 19:08:06 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/01 16:51:06 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_find_path(t_lem_in *env, t_room *room)
{
	int			i;

	i = 0;
	if (room->id == 1)
		return (1);
	while (room->doors[i])
	{
		if (room->pds - 1 == room->doors[i]->pds && room->doors[i]->pass == 0)
		{
			room->path = room->doors[i];
			room->pass = 1;
			if (ft_find_path(env, room->doors[i]) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

void			ft_solve(t_lem_in *env, t_room *r, t_room *tmp, int i)
{
	if (r->id == 0)
		env->tmp = r->pds;
	r->pass = 1;
	while (r->doors[i])
	{
		tmp = r->doors[i];
		if (tmp->pds > r->pds + 1)
		{
			tmp->pds = r->pds + 1;
			ft_solve(env, r->doors[i], NULL, 0);
		}
		else if (tmp->pds == 0)
			tmp->pds = r->pds + 1;
		i++;
	}
	i = 0;
	while (r->doors[i])
	{
		env->room = r;
		if ((env->tmp == 0 || env->tmp > r->pds + 1) && r->doors[i]->pass == 0)
			ft_solve(env, r->doors[i], NULL, 0);
		i++;
	}
	return ;
}

int				ft_resolution(t_lem_in *env)
{
	env->end->pds = 1;
	env->tmp = 0;
	ft_solve(env, env->end, NULL, 0);
	env->room = env->start->begin;
	while (env->room)
	{
		env->room->pass = 0;
		if (env->room->next == NULL)
			break ;
		env->room = env->room->next;
	}
	ft_find_path(env, env->start);
	env->room = env->start;
	while (env->room)
	{
		(env->nb_path)++;
		if (env->room->path == NULL)
			break ;
		env->room = env->room->path;
	}
	if (env->room->id != env->end->id)
		ft_error_lem_in(NULL, env);
	return (0);
}
