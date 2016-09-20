/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:01:08 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/20 12:22:14 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*ft_new_room(t_lem_in *env)
{
	t_room		*new_room;
	static int	id = 2;

	if (!(new_room = (t_room*)malloc(sizeof(t_room))))
		ft_error_lem_in("Malloc error");
	new_room->name = ft_strnew(ft_strlen(env->tmp_name));
	new_room->name = ft_strcpy(new_room->name, env->tmp_name);
	new_room->coo1 = env->tmp_coo1;
	new_room->coo2 = env->tmp_coo2;
	new_room->pass = 0;
	new_room->path = NULL;
	if (env->t_start == 1)
	{
		env->start = new_room;
		new_room->id = 0;
		env->t_start = 2;
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