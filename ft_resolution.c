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
// 			// ft_printf("[%s]\n", start->doors[i]->name);
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
// 			// ft_printf("avance [%s]\n", start->name);
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
// 			// ft_printf("nope [%s]\n", start->doors[i]->name);
// 			if ((*nb) >= env->tmp)
// 				(*nb)--;
// 		}
// 		i++;

// 	}
// 	// if (start->nb_doors == 1 && )
// 	// 	ft_printf("IMPASSE [%s]\n", start->name);
// 	(*nb)--;
// 	start->pass = 0;

// 	return (0);
// }

int				ft_solve(t_lem_in *env, t_room *room)
{
	int			i;

	i = 0;
	if (room->id == 1)
		return (1);
	while (room)
	{
		while (room->doors[i])
		{
			if (room->doors[i]->pds == 0 || room->doors[i]->pds > room->pds + 1)
			{
				room->doors[i]->pds = room->pds + 1;
				if (ft_solve(env, room->doors[i]) == 1)
					return (1);
			}
			i++;
		}
	}
	return (0);
}

int				ft_resolution(t_lem_in *env)
{
	int			nb;

	nb = 0;
	env->tmp = env->nb_room;
	env->start->pds++;
	// ft_solve(env, env->start, &nb);
	ft_solve(env, env->start);


	env->room = env->start;
	while (env->room)
	{
		ft_printf("salle %s, poids %d\n", env->room->name, env->room->pds);
		if (env->room->next == NULL)
			break ;
		env->room = env->room->next;
	}



	nb = 0;
	env->room = env->start;
	while (env->room)
	{
		nb++;
		ft_printf("path : %s\n", env->room->name);
		if (env->room->path == NULL)
			break ;
		env->room = env->room->path;
	}
	ft_printf("\n");
	if (env->room->id != env->end->id)
		// ft_error_lem_in(NULL, env);
		ft_error_lem_in("Il n'y pas de chemin vers la fin", env);
	env->nb_path = nb - 1;
	return (0);
}
