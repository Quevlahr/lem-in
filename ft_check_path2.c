/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:43:01 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/21 18:24:10 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_change_file(t_lem_in *env, char **str, int i)
{
	char		*file;

	file = env->file;
	while (file[i] != '\0' && file[i] != '\n')
		i--;
	i++;
	env->file = ft_strsub(file, 0, i);
	ft_strdel(&file);
	ft_strdel(str);
	return (0);
}

t_room			*ft_found_hash(t_lem_in *env, char *str)
{
	t_room		*room;

	room = env->hash[ft_hash(str, env)];
	if (room == NULL)
		return (NULL);
	if (ft_strcmp(room->name, str) == 0)
		return (room);
	else
	{
		while (room != NULL)
		{
			room = room->nxt_hash;
			if (room != NULL && ft_strcmp(room->name, str) == 0)
				return (room);
		}
	}
	return (NULL);
}
