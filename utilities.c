/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:37:18 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/22 18:44:30 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_error_lem_in(char *str)
{
	if (str != NULL)
		ft_printf("%s\n", str);
	else
		ft_printf("ERROR\n");
	exit(EXIT_FAILURE);
}

void			ft_put_lem_in(t_lem_in *env)
{
	ft_printf("nb fourmis : %d\n\n", env->nb_ant);
	ft_printf("start room : %s\nend room : %s\n", env->start->name, env->end->name);
	for (int i = 0; env->start->doors[i]; i++)
		ft_printf("start connect to : %s\n", env->start->doors[i]->name);
	for (int i = 0; env->end->doors[i]; i++)
		ft_printf("end connect to : %s\n", env->end->doors[i]->name);
	ft_printf("\n");
	int i;
	env->room = env->room->begin;
	while (env->room)
	{
		i = 0;
		ft_printf("room : %s, id : %d, pass : %d.\n", env->room->name, env->room->id, env->room->pass);
		while (env->room->doors[i])
		{
			ft_printf("\tconnect to : %s\n", env->room->doors[i]->name);
			i++;
		}
		if (env->room->next == NULL)
			break ;
		env->room = env->room->next;
	}
}

void			free_all(t_lem_in **env)
{
	t_room		*tmp;

	(*env)->room = (*env)->start;
	while ((*env)->room)
	{
		tmp = (*env)->room->next;
		ft_strdel(&(*env)->room->name);
		free((*env)->room->doors);
		(*env)->room->doors = NULL;
		free((*env)->room);
		(*env)->room = tmp;
		if (!(*env)->room->next)
			break ;
	}
	free((*env)->room);
	ft_strdel(&(*env)->tmp_name);
	ft_strdel(&(*env)->file);
}