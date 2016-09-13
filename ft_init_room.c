/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:29:12 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/13 19:02:52 by quroulon         ###   ########.fr       */
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
	ft_printf("%s, %d, %d\n", env->tmp_name, env->tmp_coo1, env->tmp_coo2);
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

int				ft_check_room(char *file, t_lem_in **env)
{
	int			i;
	int			j;

	i = 0;
	while (file[i] != '\0' && file[i] != '\n')
		i++;
	i++;
	while (file[i] != '\0')
	{
		j = i;
		if (file[i] == '#')
		{
			i++;
			if (file[i] == '#')
			{
				while (file[i] != '\0' && file[i] != '\n')
					i++;
				//start end
			}
			else
				while (file[i] != '\0' && file[i] != '\n')
					i++;
			i++;
		}
		else if (file[i] == 'L')
			ft_error_lem_in("Une salle commence par la lettre 'L'");
		else
		{
			(*env)->tmp = 0;
			while (file[i] != '\0' && file[i] != '\n')
			{
				if (file[i] == ' ')
					(*env)->tmp++;
				i++;
			}
			if ((*env)->tmp == 2 && i - j >= 5)
				i = ft_recup_room(j, file, *env);
			else
				break ;
		}
	}
	ft_init_doors(*env);
	return (j - 1);
}