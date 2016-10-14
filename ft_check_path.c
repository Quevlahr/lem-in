/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:09:29 by quroulon          #+#    #+#             */
/*   Updated: 2016/10/14 16:26:51 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_change_file(t_lem_in *env, char **str, int i)
{
	char		*file;

	file = env->file;
	while (file[i] != '\0' && file[i] != '\n')
		i--;
	env->file = ft_strsub(file, 0, i);
	ft_strdel(&file);
	ft_strdel(str);
}

t_room			*ft_found_hash(t_lem_in *env, char *str)
{
	t_room		*room;

	room = env->hash[ft_hash(str, env)];
	// ft_printf("name %s, str %s\n", room->name, str);
	if (room == NULL)
		return (NULL);
	if (ft_strcmp(room->name, str) == 0)
		return (room);
	else
	{
		while (room != NULL)
		{
			if (room->nxt_hash != NULL)
				room = room->nxt_hash;
			if (room != NULL && ft_strcmp(room->name, str) == 0)
				return (room);
			// else if (room != NULL)
			// {
			// 	ft_printf("collision : name %s, str %s\n", room->name, str);
			// 	ft_error_lem_in(NULL, env);
			// }
			if (room == NULL)
				return (NULL);
		}
	}
	return (NULL);
}

void			ft_check_path(char *file, t_lem_in **env, int i)
{
	int			j;
	char		*str;
	t_room		*tmp;

	i++;
	j = 0;
	str = NULL;
	tmp = NULL;
	while (file[i] != '\0')
	{
		if (file[i] == '#')
			while (file[i] != '\n')
				i++;
		else
		{
			j = i;
			while (file[j] != '\0' && file[j] != '-')
				j++;
			if (file[j] == '\0')
				ft_error_lem_in(NULL, *env);
			str = ft_strsub(file, i, j - i);
			if ((tmp = ft_found_hash(*env, str)) == NULL)
			{
				ft_change_file(*env, &str, i);
				return ;
			}
			ft_strdel(&str);

			j++;
			while (file[i] != '\n')
				i++;

			str = ft_strsub(file, j, i - j);
			if (((*env)->room = ft_found_hash(*env, str)) == NULL)
			{
				ft_change_file(*env, &str, i);
				return ;
			}
			ft_strdel(&str);

			j = 0;
			while (tmp->doors[j] != NULL)
				j++;
			tmp->doors[j] = (*env)->room;
			j = 0;
			while ((*env)->room->doors[j] != NULL)
				j++;
			(*env)->room->doors[j] = tmp;
		}
		i++;
	}
}
