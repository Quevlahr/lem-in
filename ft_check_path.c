/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:09:29 by quroulon          #+#    #+#             */
/*   Updated: 2016/10/18 14:37:00 by quroulon         ###   ########.fr       */
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
	return (1);
}

t_room			*ft_found_hash(t_lem_in *env, char *str)
{
	t_room		*room;

	ft_printf("[%s]\n", str);
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

int				ft_check_path(char *file, t_lem_in **env, int i)
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
				return (ft_change_file(*env, &str, i));
			ft_strdel(&str);

			j++;
			while (file[i] != '\n')
				i++;

			str = ft_strsub(file, j, i - j);
			if (((*env)->room = ft_found_hash(*env, str)) == NULL)
				return (ft_change_file(*env, &str, --i));
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
	tmp = (*env)->room->begin;
	while (tmp)
	{
		j = 0;
		while (tmp->doors[j] != NULL)
			j++;
		tmp->nb_doors = j;
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	return (1);


	// int			j;
	// char		*str1;
	// char		*str2;
	// t_room		*tmp;

	// while (file[i] != '\0')
	// {
	// 	j = 0;
	// 	str1 = NULL;
	// 	str2 = NULL;
	// 	tmp = NULL;
	// 	i++;
	// 	while (file[i] != '\0' && file[i] != '-' && file[i] != '\n' && i++)
	// 		j++;
	// 	if (file[i] != '\0' && file[i] != '\n')
	// 	{
	// 		str1 = ft_strsub(file, i - j, j);
	// 		j = 0;
	// 		i++;
	// 		while (file[i] != '\0' && file[i] != '\n' && i++)
	// 			j++;
	// 		str2 = ft_strsub(file, i - j, j);
	// 		while ((*env)->room)
	// 		{
	// 			j = 0;
	// 			if (ft_strcmp(str1, (*env)->room->name) == 0 && tmp == NULL)
	// 				tmp = (*env)->room;
	// 			else if (ft_strcmp(str2, (*env)->room->name) == 0 && tmp == NULL)
	// 				tmp = (*env)->room;
	// 			else if ((ft_strcmp(str2, (*env)->room->name) == 0 ||
	// 				ft_strcmp(str1, (*env)->room->name) == 0) && tmp != NULL)
	// 			{
	// 				while ((*env)->room->doors[j] != NULL)
	// 					j++;
	// 				(*env)->room->doors[j] = tmp;
	// 				j = 0;
	// 				while (tmp->doors[j] != NULL)
	// 					j++;
	// 				tmp->doors[j] = (*env)->room;
	// 			}
	// 			if ((*env)->room->next == NULL)
	// 				break ;
	// 			(*env)->room = (*env)->room->next;
	// 		}
	// 		(*env)->room = (*env)->room->begin;
	// 	}
	// 	ft_strdel(&str1);
	// 	ft_strdel(&str2);
	// }
	// return (0);

}
