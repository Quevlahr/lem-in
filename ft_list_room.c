/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:01:08 by quroulon          #+#    #+#             */
/*   Updated: 2016/10/18 18:50:07 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_push_hash_room(t_lem_in *env, t_room *new, t_room **hash_room)
{
	t_room		*tmp;

	tmp = (*hash_room);
	if ((*hash_room) == NULL)
		(*hash_room) = new;
	else
	{
		while (tmp != NULL)
		{
			if (ft_strcmp(tmp->name, new->name) == 0)
			{
				ft_strdel(&new->name);
				free(new);
				ft_error_lem_in(NULL, env);
			}
			if (tmp->nxt_hash == NULL)
			{
				tmp->nxt_hash = new;
				break ;
			}
			else
				tmp = tmp->nxt_hash;
		}
	}
}

t_room			*ft_new_room(t_lem_in *env)
{
	t_room		*new_room;
	static int	id = 2;

	if (!(new_room = (t_room*)malloc(sizeof(t_room))))
		ft_error_lem_in(NULL, env);
	new_room->name = ft_strdup(env->tmp_name);
	new_room->coo1 = env->tmp_coo1;
	new_room->coo2 = env->tmp_coo2;
	new_room->pass = 0;
	new_room->pass2 = 0;
	new_room->ant = 0;
	new_room->dead_end = 0;
	new_room->nb_doors = 0;

	new_room->pds = 0;

	new_room->h_ant = NULL;
	new_room->path = NULL;
	new_room->tmp_path = NULL;
	new_room->nxt_hash = NULL;
	new_room->doors = NULL;
	if (env->t_start == 1)
	{
		env->start = new_room;
		new_room->id = 0;
		env->t_start = 2;
		new_room->ant = env->nb_ant;
	}
	else if (env->t_end == 1)
	{
		env->end = new_room;
		new_room->id = 1;
		env->t_end = 2;
	}
	else
	{
		new_room->id = id;
		id++;
	}
	ft_strdel(&env->tmp_name);
	ft_push_hash_room(env, new_room, &env->hash[ft_hash(new_room->name, env)]);
	return (new_room);
}

void			ft_push_room(t_lem_in *env)
{
	if (env->room == NULL)
	{
		env->room = ft_new_room(env);
		env->room->next = NULL;
		env->room->begin = env->room;
	}
	else
	{
		while (env->room->next)
			env->room = env->room->next;
		env->room->next = ft_new_room(env);
		env->room->next->begin = env->room->begin;
		env->room = env->room->next;
		env->room->next = NULL;
	}
}

int				ft_len_room(t_room *room)
{
	int			nb;

	nb = 0;
	while (room)
	{
		nb++;
		room = room->next;
	}
	return (nb);
}