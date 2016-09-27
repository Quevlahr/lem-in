/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:50:06 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/27 15:38:19 by quroulon         ###   ########.fr       */
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

char			*ft_record(char *tab, int num, char *name)
{
	int			i;
	int			len;
	char		*char_num;
	char		*tab2;
	char		*tmp;

	i = 0;
	tab2 = NULL;
	tmp = NULL;
	char_num = ft_itoa(num);
	len = 3 + 1 + ft_strlen(char_num) + ft_strlen(name);

	tab2 = (char*)malloc(sizeof(char) * len);
	while (i < len)
		tab2[i++] = '\0';
	tab2 = ft_strcat(tab2, "L");
	tab2 = ft_strcat(tab2, char_num);
	tab2 = ft_strcat(tab2, "-");
	tab2 = ft_strcat(tab2, name);
	tab2 = ft_strcat(tab2, " ");
	if (tab == NULL)
		tab = tab2;
	else
	{
		tmp = tab;
		tab = ft_strjoin(tab2, tmp);
		ft_strdel(&tab2);
		ft_strdel(&tmp);
	}
	ft_strdel(&char_num);
	return (tab);
}

void			ft_put_solution(t_lem_in *env)
{
	int			num;
	char		*tab;
	t_room		*tmp;
	t_ant		*fake1;
	t_ant		*fake2;

	num = 1;
	fake1 = NULL;
	tab = NULL;
	while (env->end->ant < env->nb_ant)
	{
		tmp = env->start->path;
		fake2 = NULL;
		if (tab != NULL)
			ft_strdel(&tab);

		fake1 = tmp->h_ant;
		if (num - 1 <= env->start->ant)
			tmp->h_ant = ft_new_ant(num++, &tmp);
		else
			tmp->h_ant = NULL;
		tmp = tmp->path;

		while (tmp)
		{
			if (tmp->id == env->end->id && tmp->h_ant != NULL)
				free(tmp->h_ant);
			else
				fake2 = tmp->h_ant;
			tmp->h_ant = fake1;
			fake1 = fake2;
			if (tmp->path == NULL)
				break ;
			tmp = tmp->path;
		}
		if (tmp->id == env->end->id && fake1 != NULL)
			tmp->ant += 1;
		tmp = env->start->path;
		while (tmp)
		{
			if (tmp->h_ant != NULL)
				tab = ft_record(tab, tmp->h_ant->num, tmp->name);
			if (tmp->path == NULL)
				break ;
			tmp = tmp->path;
		}
		ft_printf("%s\n", tab);
	}
	free(env->end->h_ant);
	env->end->h_ant = NULL;
	ft_strdel(&tab);
}
