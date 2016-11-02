/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:50:06 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/02 18:56:32 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char		*ft_concat_ant(char *num, char *name, int *space)
{
	int			len;
	char		*concat_ant;

	concat_ant = NULL;
	len = 2 + ft_strlen(num) + ft_strlen(name);
	if (*space != 0)
		len++;
	concat_ant = ft_strnew(len);
	concat_ant = ft_strcat(concat_ant, "L");
	concat_ant = ft_strcat(concat_ant, num);
	concat_ant = ft_strcat(concat_ant, "-");
	concat_ant = ft_strcat(concat_ant, name);
	if (*space != 0)
		concat_ant = ft_strcat(concat_ant, " ");
	*space = 1;
	ft_strdel(&num);
	return (concat_ant);
}

static char		*ft_record(char *tab, char *concat_ant)
{
	char		*tmp;

	tmp = NULL;
	if (tab == NULL)
		tab = concat_ant;
	else
	{
		tmp = tab;
		tab = ft_strjoin(concat_ant, tmp);
		ft_strdel(&concat_ant);
		ft_strdel(&tmp);
	}
	return (tab);
}

static void		ft_final_affichage(t_room *tmp)
{
	int			space;
	char		*tab;

	tab = NULL;
	space = 0;
	while (tmp)
	{
		if (tmp->h_ant != NULL)
			tab = ft_record(tab, ft_concat_ant(ft_itoa(tmp->h_ant->num),
												tmp->name, &space));
		if (tmp->path == NULL)
			break ;
		tmp = tmp->path;
	}
	ft_printf("%s\n", tab);
	if (tab != NULL)
		ft_strdel(&tab);
}

static int		ft_record_ant(t_lem_in *env, t_room **tmp, int *verif)
{
	if ((*tmp)->id == env->end->id && (*tmp)->h_ant != NULL)
	{
		*verif = 1;
		free((*tmp)->h_ant);
	}
	else
		env->scd_ant = (*tmp)->h_ant;
	(*tmp)->h_ant = env->fst_ant;
	env->fst_ant = env->scd_ant;
	if ((*tmp)->path == NULL)
		return (0);
	(*tmp) = (*tmp)->path;
	return (1);
}

void			ft_put_solution(t_lem_in *env)
{
	int			num;
	int			verif;
	t_room		*tmp;

	num = 1;
	verif = 0;
	while (env->end->ant + 1 < env->nb_ant)
	{
		tmp = env->start->path;
		env->scd_ant = NULL;
		env->fst_ant = tmp->h_ant;
		if (num <= env->start->ant)
			tmp->h_ant = ft_new_ant(num++, &tmp);
		else
			tmp->h_ant = NULL;
		if (tmp->path)
			tmp = tmp->path;
		while (tmp)
		{
			if (ft_record_ant(env, &tmp, &verif) == 0)
				break ;
		}
		if (tmp->id == env->end->id && verif != 0)
		{
			verif = 0;
			tmp->ant += 1;
		}
		tmp = env->start->path;
		ft_final_affichage(tmp);
	}
	free(env->end->h_ant);
	env->end->h_ant = NULL;
}
