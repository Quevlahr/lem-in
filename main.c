/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:42:29 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/13 12:10:36 by quroulon         ###   ########.fr       */
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

int				ft_nb_ants(char *file)
{
	int			i;

	i = 0;
	while (ft_isdigit(file[i]) == 1)
		i++;
	while (file[i] == '\t' || file[i] == ' ')
		i++;
	if (file[i] == '\n')
	{
		i = ft_atoi(file);
		return (i);
	}
	else
		ft_error_lem_in("Le nombre de fourmis est manquant ou au mauvais format");
	return (0);
}

int				ft_check_room(char *file, t_lem_in **env)
{
	int			i;
	int			j;

	i = 0;
	(*env)->tmp_coo1 = 0;
	(*env)->tmp_coo2 = 0;
	(*env)->tmp_name = NULL;
	while (file[i] != '\0' && file[i] != '\n')
		i++;
	i++;
	while (file[i] != '\0')
	{
		j = 0;
		while (file[i] != '\0' && file[i] != ' ' && file[i] != '\n' && i++)
			j++;
		if (file[i] == '\n')
			break ;
		(*env)->tmp_name = ft_strsub(file, i - j, j);
		i++;
		(*env)->tmp_coo1 = ft_atoi(file + i);
		while (file[i] != '\0' && ft_isdigit(file[i]) == 1)
			i++;
		i++;
		(*env)->tmp_coo2 = ft_atoi(file + i);
		while (file[i] != '\0' && ft_isdigit(file[i]) == 1)
			i++;
		i++;
		ft_push_room(*env);
	}
	(*env)->nb_room = ft_len_room((*env)->room->begin);
	(*env)->room = (*env)->room->begin;
	while ((*env)->room->next)
	{
		(*env)->room->doors = (t_room**)malloc(sizeof(t_room*) * (*env)->nb_room);
		j = 0;
		while (j < (*env)->nb_room)
		{
			(*env)->room->doors[j] = NULL;
			j++;
		}
		(*env)->room = (*env)->room->next;
	}
	(*env)->room->doors = (t_room**)malloc(sizeof(t_room*) * (*env)->nb_room);
	(*env)->room = (*env)->room->begin;
	return (i);

}

int				ft_check_path(char *file, t_lem_in **env, int i)
{
	int			j;
	char		*str1;
	char		*str2;
	t_room		*tmp;

	str1 = NULL;
	str2 = NULL;
	tmp = NULL;
	while (file[i] != '\0')
	{
		j = 0;
		i++;
		while (file[i] != '\0' && file[i] != '-' && i++)
			j++;
		ft_printf("iiiiii%c, %d, %d\n", file[i - j], i, j);
		str1 = ft_strsub(file, i - j, j);
		j = 0;
		while (file[i] != '\0' && file[i] != '\n' && i++)
			j++;
		str2 = ft_strsub(file, i - j, j);
	}
	while ((*env)->room->next)
	{
			ft_printf("str1 : %s, room->name : %s\n", str1, (*env)->room->name);
		if (ft_strcmp(str1, (*env)->room->name) == 0 && tmp == NULL)
			tmp = (*env)->room;
		else if (ft_strcmp(str2, (*env)->room->name) == 0 && tmp == NULL)
			tmp = (*env)->room;
		else if ((ft_strcmp(str2, (*env)->room->name) == 0 ||
			ft_strcmp(str1, (*env)->room->name) == 0) && tmp != NULL)
		{
			j = 0;
			while ((*env)->room->doors[j] != NULL)
				j++;
			(*env)->room->doors[j] = tmp;
			j = 0;
			while (tmp->doors[j] != NULL)
				j++;
			tmp->doors[j] = (*env)->room;
		}
		else if (ft_strcmp(str1, (*env)->room->name) == 0)
			(*env)->room->doors[0] = tmp;
		(*env)->room = (*env)->room->next;
	}
	(*env)->room = (*env)->room->begin;
	return (0);
}

int				main(void)
{
	char		*file;
	t_lem_in	*env;

	env = (t_lem_in*)malloc(sizeof (t_lem_in));
	env->room = NULL;
	file = NULL;
	ft_get_file(&file);
	env->nb_ant = ft_nb_ants(file);
	ft_check_path(file, &env, ft_check_room(file, &env));

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
		ft_printf("%d\n", i);
		env->room = env->room->next;
	}
	return (0);
}
