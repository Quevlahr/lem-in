/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:29:12 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/01 19:56:53 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_init_doors(t_lem_in *env)
{
	int			j;

	j = 0;
	env->room = env->room->begin;
	while (env->room)
	{
		env->room->doors = (t_room**)malloc(sizeof(t_room*) * env->nb_room);
		j = 0;
		while (j < env->nb_room)
		{
			env->room->doors[j] = NULL;
			j++;
		}
		if (env->room->next == NULL)
			break ;
		env->room = env->room->next;
	}
}

static int		ft_recup_room(int i, char *file, t_lem_in *env)
{
	int			j;

	j = i;
	while (file[i] != ' ')
		i++;
	env->tmp_name = ft_strsub(file, j, i - j);
	i++;
	env->tmp_coo1 = ft_atoi(file + i);
	while (file[i] != '\0' && ft_isdigit(file[i]) == 1)
		i++;
	i++;
	env->tmp_coo2 = ft_atoi(file + i);
	while (file[i] != '\0' && ft_isdigit(file[i]) == 1)
		i++;
	i++;
	ft_push_room(env);
	return (i);
}

static int		ft_verif_room(int j, int *i, char *file, t_lem_in *env)
{
	env->tmp = 0;
	while (file[(*i)] != '\0' && file[(*i)] != '\n')
	{
		if (file[(*i)] == ' ')
			env->tmp++;
		(*i)++;
	}
	if (env->tmp == 2 && (*i) - j >= 5)
		(*i) = ft_recup_room(j, file, env);
	else
		return (0);
	return (1);
}

static void		ft_init_hashtable(t_lem_in **env, int k)
{
	int			tmp;

	tmp = (int)((*env)->nb_room * 1.5);
	(*env)->hash = (t_room**)malloc(sizeof(t_room*) * tmp);
	while (k < tmp)
	{
		(*env)->hash[k] = NULL;
		k++;
	}
}

int				ft_check_room(char *file, t_lem_in **env, int i)
{
	int			j;

	ft_init_hashtable(env, 0);
	while (file[i] != '\0')
	{
		j = i;
		if ((*env)->t_start == 1 && (*env)->t_end == 1)
			ft_error_lem_in(NULL, (*env));
		if (file[i] == '#' && i++)
			ft_hashtag(&i, file, *env);
		else if (ft_verif_room(j, &i, file, *env) == 0)
			break ;
	}
	while (file[i] != '\0')
	{
		if (file[i] == '#' && i++)
			ft_hashtag(&i, file, *env);
		i++;
	}
	ft_init_doors(*env);
	if ((*env)->start == NULL)
		ft_error_lem_in(NO_START, *env);
	else if ((*env)->end == NULL)
		ft_error_lem_in(NO_END, *env);
	return (j);
}
