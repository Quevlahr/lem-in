/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 19:08:06 by quroulon          #+#    #+#             */
/*   Updated: 2016/10/18 19:03:06 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// int				ft_solve(t_lem_in *env, t_room *start, int *nb)
// {
// 	int			i;
// 	int			tmp = 1;

// 	i = 0;
// 	start->pass = 1;
// 	start->pass2++;
// 	while (start->doors[i])
// 	{
// 		if (start->doors[i]->id == 1)
// 		{
// 			ft_printf("[%s]\n", start->doors[i]->name);
// 			(*nb)++;
// 			start->pass = 0;
// 			if (start->id == 0)
// 				start->path = start->doors[i];
// 			else
// 				start->tmp_path = start->doors[i];
// 			return (1);
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (start->doors[i])
// 	{
// 		if (start->doors[i]->pass == 0 && start->doors[i]->nb_doors > 1)
// 		{
// 			ft_printf("avance [%s]\n", start->name);
// 			start->tmp_path = start->doors[i];
// 			(*nb)++;
// 			if ((*nb) < env->tmp && (tmp = ft_solve(env, start->doors[i], nb)))
// 			{
// 				env->tmp = *nb;
// 				(*nb) -= 2;
// 				env->room = env->start;
// 				while (env->room)
// 				{
// 					env->room->path = env->room->tmp_path;
// 					if (!env->room->path)
// 						break ;
// 					env->room = env->room->tmp_path;
// 				}
// 			}
// 			ft_printf("nope [%s]\n", start->doors[i]->name);
// 			if ((*nb) >= env->tmp)
// 				(*nb)--;
// 		}
// 		i++;

// 	}
// 	(*nb)--;
// 	start->pass = 0;

// 	return (0);
// }

int				ft_find_path(t_lem_in *env, t_room *room, int *nb)
{
	int			i;

	i = 0;
	if (room->id == 1)
	{
		ft_printf("FIN %s\n", room->name);
		// room->pass = 1;
		return (1);
	}
	while (room->doors[i])
	{
		if (room->pds - 1 == room->doors[i]->pds && room->doors[i]->pass == 0)
		{
			(*nb)++;
			ft_printf("%5s\n", room->name);
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
		if (tmp->pds > room->pds + 1  && room->doors[i]->id != 0)
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
		if ((env->tmp == 0 || env->tmp > room->pds + 1) && room->doors[i]->pass == 0)// && room->doors[i]->id != 0)
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

	env->room = env->room->begin;
	while (env->room)
	{
		env->room->pass = 0;
		if (env->room->next == NULL)
			break ;
		env->room = env->room->next;
	}

	int tmp = 0;
	tmp = env->start->pds;
	int i = 0;
	env->path = (t_room**)malloc(sizeof(t_room*) * env->start->nb_doors);
	while (i < env->start->nb_doors)
		env->path[i++] = NULL;
	i = 0;
	while (env->start->doors[i])
	{
		env->start->pds = env->start->doors[i]->pds + 1;
		if (ft_find_path(env, env->start, &nb) == 1)
		{
			env->path[i] = env->start->doors[i];
		}
		ft_printf("\n\nSTOP\n\n");
		i++;
	}


	// nb = env->end->pds;
	// env->room = env->room->begin;
	// while (env->room)
	// {
	// 	ft_printf("salle %s, poids %d\n", env->room->name, env->room->pds);
	// 	if (env->room->next == NULL)
	// 		break ;
	// 	env->room = env->room->next;
	// }



	nb = 0;
	i = 0;
	while (env->path[i])
	{
		env->room = env->path[i];
		while (env->room)
		{
			nb++;
			ft_printf("path : %s\n", env->room->name);
			if (env->room->path == NULL)
				break ;
			env->room = env->room->path;
		}
		ft_printf("\n");
		i++;
	}
	if (env->room->id != env->end->id)
		ft_error_lem_in(NULL, env);
		// ft_error_lem_in("Il n'y pas de chemin vers la fin", env);
	env->nb_path = nb - 1;
	return (0);
}
