/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:42:29 by quroulon          #+#    #+#             */
/*   Updated: 2016/10/07 18:18:06 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		ft_error_lem_in("Le nombre de fourmis est manquant ou au mauvais format", *env);
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
		ft_strdel(&str1);
		ft_strdel(&str2);
	}
	return (0);
}

void			ft_putsmall_solution(t_lem_in *env)
{
	int			num;

	num = 1;
	while (num - 1 != env->nb_ant)
	{
		ft_printf("L%d-%s\n", num, env->start->path->name);
		num++;
	}

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
	env->nb_path = 1;
	env->tmp_name = NULL;
	env->tmp = 0;
	env->t_start = 0;
	env->t_end = 0;
	env->file = NULL;
	env->fst_part = 0;
	env->scd_part = 0;
	env->thd_part = 0;

	// ft_get_file(&(env->file), env, 0);
	ft_get_file(&env->file, env);
	ft_printf("GET FILE\n");
	env->nb_ant = ft_nb_ants(env->file, &env);
	ft_check_path(env->file, &env, ft_check_room(env->file, &env));
	ft_printf("GET ROOM\n");
	// ft_printf("%s\n\n", env->file);
	ft_resolution(env);
	ft_printf("GET PATH\n");
	if (env->nb_path == 1)
		ft_putsmall_solution(env);
	else
		ft_put_solution(env);
	free_all(&env);
	free(env);
	// ft_put_lem_in(env);
	return (0);
}
