/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:50:06 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/02 18:28:49 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant			*ft_new_ant(int num, t_room **room)
{
	t_ant		*ant;

	ant = (t_ant*)malloc(sizeof(t_ant));
	ant->room = (*room);
	ant->num = num;
	return (ant);
}

// char			*ft_record(char *tab, int num, char *name, int *space)
// {
// 	int			i;
// 	int			len;
// 	char		*char_num;
// 	char		*tab2;
// 	char		*tmp;

// 	i = 0;
// 	tab2 = NULL;
// 	tmp = NULL;
// 	char_num = ft_itoa(num);
// 	len = 3 + 1 + ft_strlen(char_num) + ft_strlen(name);

// 	tab2 = (char*)malloc(sizeof(char) * len);
// 	while (i < len)
// 		tab2[i++] = '\0';
// 	tab2 = ft_strcat(tab2, "L");
// 	tab2 = ft_strcat(tab2, char_num);
// 	tab2 = ft_strcat(tab2, "-");
// 	tab2 = ft_strcat(tab2, name);
// 	if (*space != 0)
// 		tab2 = ft_strcat(tab2, " ");
// 	*space = 1;
// 	if (tab == NULL)
// 		tab = tab2;
// 	else
// 	{
// 		tmp = tab;
// 		tab = ft_strjoin(tab2, tmp);
// 		ft_strdel(&tab2);
// 		ft_strdel(&tmp);
// 	}
// 	ft_strdel(&char_num);
// 	return (tab);
// }

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

void			ft_put_solution(t_lem_in *env)
{
	int			num;
	int			verif;
	// int			space;
	t_room		*tmp;
	t_ant		*fake1;
	t_ant		*fake2;

	num = 1;
	fake1 = NULL;
	verif = 0;
	while (env->end->ant + 1 < env->nb_ant)
	{
		tmp = env->start->path;
		fake2 = NULL;
		fake1 = tmp->h_ant;
		if (num <= env->start->ant)
			tmp->h_ant = ft_new_ant(num++, &tmp);
		else
			tmp->h_ant = NULL;
		if (tmp->path)
			tmp = tmp->path;
		while (tmp)
		{
			if (tmp->id == env->end->id && tmp->h_ant != NULL)
			{
				verif = 1;
				free(tmp->h_ant);
			}
			else
				fake2 = tmp->h_ant;
			tmp->h_ant = fake1;
			fake1 = fake2;
			if (tmp->path == NULL)
				break ;
			tmp = tmp->path;
		}
		if (tmp->id == env->end->id && verif != 0)
		{
			verif = 0;
			tmp->ant += 1;
		}
		tmp = env->start->path;
		ft_final_affichage(tmp);
		// space = 0;
		// while (tmp)
		// {
		// 	if (tmp->h_ant != NULL)
		// 		tab = ft_record(tab, ft_concat_ant(ft_itoa(tmp->h_ant->num),
		// 											tmp->name, &space));
		// 	if (tmp->path == NULL)
		// 		break ;
		// 	tmp = tmp->path;
		// }
		// ft_printf("%s\n", tab);
	}
	free(env->end->h_ant);
	env->end->h_ant = NULL;
}
