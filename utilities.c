/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:37:18 by quroulon          #+#    #+#             */
/*   Updated: 2016/10/16 17:17:33 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			full_clr_gnl(void)
{
	char		*line;

	line = NULL;
	if (get_next_line(0, &line) > 0)
	{
		ft_strdel(&line);
		while (get_next_line(0, &line) > 0)
			ft_strdel(&line);
	}
	ft_strdel(&line);
}

void			ft_error_lem_in_start(char *str, t_lem_in *env)
{
	ft_strdel(&env->file);
	ft_strdel(&str);
	if (env->room != NULL)
		free_all(&env);
	free(env);
	// full_clr_gnl();
	ft_printf("ERROR\n");
	exit(EXIT_FAILURE);
}

void			ft_error_lem_in(char *str, t_lem_in *env)
{
	ft_strdel(&env->file);
	if (env->room != NULL)
		free_all(&env);
	free(env);
	if (str != NULL)
		ft_printf("%s\n", str);
	else
		ft_printf("ERROR\n");
	// full_clr_gnl();
	exit(EXIT_FAILURE);
}

void			ft_put_hashtable(t_lem_in *env)
{
	int			k;

	k = 0;
	t_room	*tmp2 = NULL;
	while (k < (int)(env->nb_room * 1.5))
	{
		if (env->hash[k] != NULL)
			ft_printf("salle %s, hashé %d\n", env->hash[k]->name, k);
		if (env->hash[k] != NULL && env->hash[k]->nxt_hash != NULL)
		{
			ft_printf("En collision avec :\n");
			tmp2 = env->hash[k];
			while (tmp2 != NULL)
			{
				tmp2 = tmp2->nxt_hash;
				ft_printf("\tsalle %s, hashé %d\n", tmp2->name, k);
				if (tmp2->nxt_hash == NULL)
					break ;
			}
		}
		k++;
	}
	ft_printf("\n");
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
	ft_printf("\n");
}

void			free_all(t_lem_in **env)
{
	int			i;
	t_room		*tmp;

	(*env)->room = (*env)->room->begin;
	while ((*env)->room)
	{
		i = 0;
		tmp = (*env)->room->next;
		ft_strdel(&(*env)->room->name);
		while (i < (*env)->nb_room && (*env)->room->doors != NULL)
		{
			if ((*env)->room->doors[i] != NULL)
				(*env)->room->doors[i] = NULL;
			free((*env)->room->doors[i]);
			i++;
		}
		free((*env)->room->doors);
		free((*env)->room);
		(*env)->room = tmp;
	}
	free((*env)->hash);
	ft_strdel(&(*env)->tmp_name);
	ft_strdel(&(*env)->file);
}


	





