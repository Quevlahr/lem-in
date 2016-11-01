/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:37:18 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/01 15:43:31 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_error_lem_in_start(char *msg, char *str, t_lem_in *env)
{
	ft_strdel(&env->file);
	ft_strdel(&str);
	if (env->room != NULL)
		free_all(&env);
	free(env);
	if (msg != NULL)
		ft_printf("ERROR\n", msg);
	else
		ft_printf("ERROR\n");
	exit(EXIT_FAILURE);
}

void			ft_error_lem_in(char *str, t_lem_in *env)
{
	ft_strdel(&env->file);
	if (env->room != NULL)
		free_all(&env);
	free(env);
	if (str != NULL)
		ft_printf("ERROR\n", str);
	else
		ft_printf("ERROR\n");
	exit(EXIT_FAILURE);
}

void			free_all(t_lem_in **env)
{
	int			i;
	t_room		*tmp;

	(*env)->room = (*env)->room->begin;
	while ((*env)->room)
	{
		i = 0;
		tmp = (*env)->room->next;
		ft_strdel(&(*env)->room->name);
		while (i < (*env)->nb_room && (*env)->room->doors != NULL)
		{
			if ((*env)->room->doors[i] != NULL)
				(*env)->room->doors[i] = NULL;
			free((*env)->room->doors[i]);
			i++;
		}
		free((*env)->room->doors);
		free((*env)->room);
		(*env)->room = tmp;
	}
	free((*env)->hash);
	ft_strdel(&(*env)->tmp_name);
	ft_strdel(&(*env)->file);
}
