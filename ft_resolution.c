/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 19:08:06 by quroulon          #+#    #+#             */
/*   Updated: 2016/10/28 15:08:00 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_find_path(t_lem_in *env, t_room *room, int *nb)
{
	int			i;

	i = 0;
	if (room->id == 1)
	{
		// ft_printf("FIN %s\n\n\n", room->name);
		// room->pass = 1;
		return (1);
	}
	while (room->doors[i])
	{
		if (room->pds - 1 == room->doors[i]->pds && room->doors[i]->pass == 0)
		{
			(*nb)++;
			// ft_printf("%5s\n", room->name);
			room->path = room->doors[i];
			// ft_printf("%3d > %3d\n", room->pds, room->doors[i]->pds);
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
	// ft_printf("SALLE %s\n", room->name);
	if (room->id == 0)
		env->tmp = room->pds;
	room->pass = 1;
	while (room->doors[i])
	{
		tmp = room->doors[i];
		if (tmp->pds > room->pds + 1)//  && room->doors[i]->id != 0)
		{
			tmp->pds = room->pds + 1;
			// ft_printf("salle %s, pds %d\n", tmp->name, tmp->pds);
			ft_solve(env, room->doors[i]);
		}
		else if (tmp->pds == 0)
		{
			tmp->pds = room->pds + 1;
			// ft_printf("salle %s, pds %d\n", tmp->name, tmp->pds);
		}
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


	// ft_solve(env, env->start, &nb);
	

	ft_solve(env, env->end);
	env->room = env->start->begin;
	while (env->room)
	{
		env->room->pass = 0;
		if (env->room->next == NULL)
			break ;
		env->room = env->room->next;
	}

	// int tmp = 0;
	// tmp = env->start->pds;
	// int i = 0;

	ft_find_path(env, env->start, &nb);

	// TROUVER PLUSIEURS CHEMINS
	// env->path = (t_path**)malloc(sizeof(t_path*) * env->start->nb_doors);
	// while (i < env->start->nb_doors)
	// 	env->path[i++] = NULL;
	// i = 0;
	// while (env->start->doors[i])
	// {
	// 	env->start->pds = env->start->doors[i]->pds + 1;
	// 	if (ft_find_path(env, env->start, &nb) == 1)
	// 	{
	// 		env->path[i] = (t_path*)malloc(sizeof(t_path));
	// 		env->path[i]->room = env->start->doors[i];
	// 		env->path[i]->len = nb;
	// 	}
	// 	ft_printf("\n\nSTOP\n\n");
	// 	i++;
	// }
	// env->nb_path = i;


	nb = 0;
	// i = 0;
	// while (env->path[i])
	// {
	// 	env->room = env->path[i]->room;
	env->room = env->start;
		while (env->room)
		{
			nb++;
			// ft_printf("path : %s\n", env->room->name);
			if (env->room->path == NULL)
				break ;
			env->room = env->room->path;
		}
		// ft_printf("\n");
	// 	i++;
	// }
	if (env->room->id != env->end->id)
		ft_error_lem_in(NULL, env);
		// ft_error_lem_in("Il n'y pas de chemin vers la fin", env);
	env->nb_path = nb;
	return (0);
}
