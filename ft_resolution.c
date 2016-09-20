/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 19:08:06 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/20 13:21:54 by quroulon         ###   ########.fr       */
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
	int			tmp = 1;

	i = 0;
	// ft_printf("room : %s, id : %d, nb : %d.\n", start->name, start->id, *nb);
	start->pass = 1;
	while (start->doors[i])
	{
		if (start->doors[i]->id == 1)
		{
			(*nb)++;
			start->pass = 0;
			// ft_printf("room : %s, id : %d, nb : %d.\n", start->doors[i]->name, start->doors[i]->id, *nb);
			ft_printf("salle : %s --> %s, nb : %d, pass : %d\n", start->name, start->doors[i]->name, *nb, start->doors[i]->pass);
			start->path = start->doors[i];
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
			ft_printf("salle : %s --> %s, nb : %d, pass : %d\n", start->name, start->doors[i]->name, *nb, start->doors[i]->pass);
			(*nb)++;
			if ((*nb) < env->tmp && (tmp = ft_solve(env, start->doors[i], nb)))
			{
				env->tmp = *nb;
				(*nb) -= 2;
				ft_printf("salle : %s <-- %s, nb : %d, pass : %d\n", start->name, start->doors[i]->name, *nb, start->doors[i]->pass);
				ft_printf("CESTBON\n");
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
			if (tmp == 0)
			{
				ft_printf("salle : %s <-- %s, nb : %d, pass : %d\n", start->name, start->doors[i]->name, *nb, start->doors[i]->pass);
			}
		}
		i++;

	}
	(*nb)--;
	// env->i--;
	// env->path[env->i] = NULL;
	start->pass = 0;
	return (0);
}

int				ft_resolution(t_lem_in *env)
{
	int			nb;

	nb = 0;
	env->tmp = env->nb_room;


	ft_solve(env, env->start, &nb);
	env->room = env->start;
	ft_printf("name : %s, id : %d, path : %s\n", env->room->name, env->room->id, env->room->path->name);
	while (env->room)
	{
		ft_printf("path : %s\n", env->room->name);
		if (env->room->path == NULL)
			break ;
		env->room = env->room->path;
	}


	// env->room = env->start;
	// while (env->room)
	// {
	// 	if (env->room->id == 1)
	// 		ft_printf("name : %s, id : %d, path : %s\n", env->room->name, env->room->id, env->room->path->name);
	// 	if (!env->room->next)
	// 		break ;
	// 	env->room = env->room->next;
	// }

	return (0);
}
