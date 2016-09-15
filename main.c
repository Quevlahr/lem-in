/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:42:29 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/15 18:39:19 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_get_file(char **file)
{
	int			fd;
	char		*buf;
	char		*tmp;

	buf = ft_strnew(BUFF_READ);
	*file = ft_strnew(0);
	fd = 0;
	while (read(fd, buf, BUFF_READ) > 0)
	{
		tmp = *file;
		*file = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
		ft_strdel(&buf);
		buf = ft_strnew(BUFF_READ);
	}
	ft_strdel(&buf);
}

int				ft_nb_ants(char *file, t_lem_in **env)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (file[i] != '\0' && file[i] == '#')
	{
		i++;
		ft_hashtag(i, &i, file, *env);
	}
	(*env)->tmp = 0;
	while (ft_isdigit(file[i]) == 1)
	{
		j++;
		i++;
	}
	if (file[i] == '\n')
	{
		(*env)->tmp = i;
		return (ft_atoi(file + (i - j)));
	}
	else
		ft_error_lem_in("Le nombre de fourmis est manquant ou au mauvais format");
	return (0);
}

int				ft_check_path(char *file, t_lem_in **env, int i)
{
	int			j;
	char		*str1;
	char		*str2;
	t_room		*tmp;

	while (file[i] != '\0')
	{
		j = 0;
		str1 = NULL;
		str2 = NULL;
		tmp = NULL;
		i++;
		while (file[i] != '\0' && file[i] != '-' && file[i] != '\n' && i++)
			j++;
		if (file[i] != '\0' && file[i] != '\n')
		{
			str1 = ft_strsub(file, i - j, j);
			j = 0;
			i++;
			while (file[i] != '\0' && file[i] != '\n' && i++)
				j++;
			str2 = ft_strsub(file, i - j, j);
			while ((*env)->room)
			{
				j = 0;
				if (ft_strcmp(str1, (*env)->room->name) == 0 && tmp == NULL)
					tmp = (*env)->room;
				else if (ft_strcmp(str2, (*env)->room->name) == 0 && tmp == NULL)
					tmp = (*env)->room;
				else if ((ft_strcmp(str2, (*env)->room->name) == 0 ||
					ft_strcmp(str1, (*env)->room->name) == 0) && tmp != NULL)
				{
					while ((*env)->room->doors[j] != NULL)
						j++;
					(*env)->room->doors[j] = tmp;
					j = 0;
					while (tmp->doors[j] != NULL)
						j++;
					tmp->doors[j] = (*env)->room;
				}
				if ((*env)->room->next == NULL)
					break ;
				(*env)->room = (*env)->room->next;
			}
			(*env)->room = (*env)->room->begin;
		}
	}
	return (0);
}

int				main(void)
{
	t_lem_in	*env;

	env = (t_lem_in*)malloc(sizeof (t_lem_in));
	env->room = NULL;
	env->nb_ant = 0;
	env->nb_room = 0;
	env->room = NULL;
	env->start = NULL;
	env->end = NULL;
	env->tmp_coo1 = 0;
	env->tmp_coo2 = 0;
	env->tmp_name = NULL;
	env->tmp = 0;
	env->t_start = 0;
	env->t_end = 0;
	env->file = NULL;

	ft_get_file(&(env->file));
	env->nb_ant = ft_nb_ants(env->file, &env);
	ft_check_path(env->file, &env, ft_check_room(env->file, &env));
	// ft_resolution(env);

	ft_printf("nb fourmis : %d\n\n", env->nb_ant);
	ft_printf("start room : %s\nend room : %s\n", env->start->name, env->end->name);
	for (int i = 0; env->start->doors[i]; i++)
		ft_printf("start connect to : %s\n", env->start->doors[i]->name);
	for (int i = 0; env->end->doors[i]; i++)
		ft_printf("end connect to : %s\n", env->end->doors[i]->name);
	int i;
	env->room = env->room->begin;
	while (env->room)
	{
		i = 0;
		ft_printf("room : %s, %d, %d\n", env->room->name, env->room->coo1, env->room->coo2);
		while (env->room->doors[i])
		{
			ft_printf("\tconnect to : %s\n", env->room->doors[i]->name);
			i++;
		}
		if (env->room->next == NULL)
			break ;
		env->room = env->room->next;
	}
	return (0);
}
