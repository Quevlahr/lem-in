/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:09:29 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/02 15:45:17 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_init_nb_doors(t_lem_in *env, int i)
{
	t_room		*tmp;

	tmp = env->room->begin;
	while (tmp)
	{
		i = 0;
		while (tmp->doors[i] != NULL)
			i++;
		tmp->nb_doors = i;
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
}

static t_room	*ft_concur_room2(t_lem_in *env, int *i, int *j)
{
	char		*str;
	char		*file;
	t_room		*tmp;

	file = env->file;
	while (file[*i] != '\0' && file[*i] != '\n')
		(*i)++;
	str = ft_strsub(file, *j, (*i) - (*j));
	if ((tmp = ft_found_hash(env, str)) == NULL)
	{
		ft_change_file(env, &str, --(*i));
		return (NULL);
	}
	ft_strdel(&str);
	return (tmp);
}

static t_room	*ft_concur_room1(t_lem_in *env, int *i, int *j)
{
	char		*str;
	char		*file;
	t_room		*tmp;

	file = env->file;
	while (file[*j] != '\0' && file[*j] != '-' && file[*j] != '\n')
		(*j)++;
	if (file[*j] == '\0')
		ft_error_lem_in(NULL, env);
	str = ft_strsub(file, *i, (*j) - (*i));
	if ((tmp = ft_found_hash(env, str)) == NULL)
	{
		ft_change_file(env, &str, *i);
		return (NULL);
	}
	ft_strdel(&str);
	(*j)++;
	return (tmp);
}

static int		ft_check_path2(t_lem_in **env, int *i, t_room *tmp)
{
	int			j;

	j = *i;
	if ((tmp = ft_concur_room1(*env, i, &j)) == NULL)
		return (0);
	if (((*env)->room = ft_concur_room2(*env, i, &j)) == NULL)
		return (0);
	j = 0;
	while (tmp->doors[j] != NULL)
		j++;
	tmp->doors[j] = (*env)->room;
	j = 0;
	while ((*env)->room->doors[j] != NULL)
		j++;
	(*env)->room->doors[j] = tmp;
	return (1);
}

int				ft_check_path(t_lem_in **env, int i)
{
	t_room		*tmp;

	tmp = NULL;
	while ((*env)->file[i] != '\0')
	{
		if ((*env)->file[i] == '#')
		{
			while ((*env)->file[i] != '\n')
				i++;
		}
		else
		{
			if (ft_check_path2(env, &i, tmp) == 0)
				return (0);
		}
		i++;
	}
	ft_init_nb_doors(*env, 0);
	return (1);
}
