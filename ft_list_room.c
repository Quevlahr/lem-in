/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:01:08 by quroulon          #+#    #+#             */
/*   Updated: 2016/10/13 12:51:10 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_push_hash_room(t_room *room, t_room **hash_room)
{
	if (*hash_room == NULL)
		*hash_room = room;
	else
	{
		while (*hash_room != NULL)
		{
			if ((*hash_room)->nxt_hash == NULL)
			{
				(*hash_room)->nxt_hash = room;
				break ;
			}
			else
				*hash_room = (*hash_room)->nxt_hash;
		}
	}
}

t_room			*ft_new_room(t_lem_in *env)
{
	t_room		*new_room;
	static int	id = 2;

	if (!(new_room = (t_room*)malloc(sizeof(t_room))))
		ft_error_lem_in("Malloc error", env);
	new_room->name = ft_strdup(env->tmp_name);
	new_room->coo1 = env->tmp_coo1;
	new_room->coo2 = env->tmp_coo2;
	new_room->pass = 0;
	new_room->path = NULL;
	new_room->tmp_path = NULL;
	new_room->ant = 0;
	new_room->h_ant = NULL;
	new_room->doors = NULL;
	new_room->nxt_hash = NULL;
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
	ft_push_hash_room(new_room, &env->hash[ft_hash(new_room->name, env)]);
	ft_printf("%s, %d\n", new_room->name, ft_hash(new_room->name, env));
	ft_strdel(&env->tmp_name);
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