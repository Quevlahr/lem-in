/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:29:12 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/28 19:10:15 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_recup_room(int i, char *file, t_lem_in *env)
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

void			ft_init_doors(t_lem_in *env)
{
	int			j;

	j = 0;
	env->nb_room = ft_len_room(env->room->begin);
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
	env->room = env->room->begin;
}

int				ft_verif_room(int j, int *i, char *file, t_lem_in *env)
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

int				ft_hashtag(int j, int *i, char *file, t_lem_in *env)
{
	char		*tmp;

	tmp = NULL;
	if (file[(*i)] == '#' && (*i)++)
	{
		env->tmp = 0;
		while (file[*i] != '\0' && file[*i] != '\n' && (*i)++)
			env->tmp++;
		tmp = ft_strsub(file, (*i) - env->tmp, env->tmp);
		if (ft_strcmp(tmp, "start") == 0 && env->t_start == 0)
		{
			env->t_start = 1;
			(*i)++;
			j += 8;
			if (ft_verif_room(j, i, file, env) == 0)
				ft_error_lem_in("La salle start n'es pas au bon format", env);
		}
		else if (ft_strcmp(tmp, "end") == 0 && env->t_end == 0)
		{
			env->t_end = 1;
			(*i)++;
			j += 6;
			if (ft_verif_room(j, i, file, env) == 0)
				ft_error_lem_in("La salle end n'es pas au bon format", env);
		}
		else
			(*i)++;
		ft_strdel(&tmp);
	}
	else
	{
		while (file[*i] != '\0' && file[*i] != '\n')
			(*i)++;
		(*i)++;
	}
	return (1);
}

int				ft_check_room(char *file, t_lem_in **env)
{
	int			i;
	int			j;

	i = (*env)->tmp;
	i++;
	while (file[i] != '\0')
	{
		j = i;
		if (file[i] == '#' && i++)
			ft_hashtag(j, &i, file, *env);
		else if (file[i] == 'L')
			ft_error_lem_in("Une salle commence par la lettre 'L'", *env);
		else if (ft_verif_room(j, &i, file, *env) == 0)
			break ;
	}
	if ((*env)->t_start == 0)
		ft_error_lem_in("Il manque une salle start", *env);
	else if ((*env)->t_end == 0)
		ft_error_lem_in("Il manque une salle end", *env);
	ft_init_doors(*env);
	return (j - 1);
}
