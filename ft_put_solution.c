/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:50:06 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/26 18:55:34 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// t_ant			**ft_init_tabpath(t_lem_in *env, t_ant **tab, int i, int *len)
// {
// 	env->room = env->start;
// 	while (env->room->path)
// 	{
// 		(*len)++;
// 		env->room = env->room->path;
// 	}
// 	tab = (t_ant**)malloc(sizeof(t_ant*) * (*len));
// 	while (i < (*len))
// 		tab[i++] = (t_ant*)malloc(sizeof(t_ant));
// 	i = 0;
// 	env->room = env->start;
// 	env->room = env->room->path;
// 	while (env->room)
// 	{
// 		tab[i]->room = env->room;
// 		tab[i]->num = 0;
// 		i++;
// 		if (env->room->path == NULL)
// 			break ;
// 		env->room = env->room->path;
// 	}
// 	return (tab);
// }

t_ant			*ft_new_ant(int num, t_room **room)
{
	t_ant		*ant;

	ant = (t_ant*)malloc(sizeof(t_ant));
	ant->room = (*room);
	ant->num = num;
	return (ant);
}

void			ft_put_solution(t_lem_in *env)
{
	int			num;
	t_room		*tmp;
	t_ant		*fake1;
	t_ant		*fake2;

	num = 1;
	fake1 = NULL;
	while (env->end->ant < env->nb_ant)
	{
		tmp = env->start->path;
		fake2 = NULL;
	

		fake1 = tmp->h_ant;
		tmp->h_ant = ft_new_ant(num++, &tmp);
		tmp = tmp->path;
	

		while (tmp && tmp->h_ant != NULL)
		{
			ft_printf("name %s, num %d\n", tmp->name, tmp->h_ant->num);
			if (fake2 == NULL)
			{
				fake1 = tmp->h_ant;
				tmp->h_ant = fake1;
			}
			else
				tmp->h_ant = fake2;
			if (tmp->path == NULL)
				break ;
			tmp = tmp->path;
			fake2 = tmp->h_ant;
			tmp->h_ant = fake1;
		}
		if (tmp->id == env->end->id)
		{
			ft_printf("AQUI\n");
			tmp->ant += 1;
			tmp->h_ant->room = NULL;
			free(tmp->h_ant);
			tmp->h_ant = NULL;
		}
		tmp = env->start->path;
		if (tmp->h_ant == NULL)
			tmp->h_ant = ft_new_ant(num++, &tmp);
		tmp = env->start->path;
		while (tmp)
		{
			if (tmp->h_ant != NULL)
				ft_printf("L%d-%s ", tmp->h_ant->num, tmp->name);
			if (tmp->path == NULL)
			{
				tmp->ant += 1;
				break ;
			}
			tmp = tmp->path;
		}
		ft_printf("\n");
	}









	// int			i;
	// int			len;
	// t_ant		**tab;

	// i = 0;
	// len = 0;
	// tab = NULL;
	// tab = ft_init_tabpath(env, tab, 0, &len);
	// while (i < len)
	// {
	// 	ft_printf("%d, %s\n", tab[i]->num, tab[i]->room->name);
	// 	i++;
	// }

	// i = 0;
	// while (i < len)
	// {
	// 	tab[i]->room = NULL;
	// 	// ft_strdel(&tab[i]->name);
	// 	free(tab[i]);
	// 	i++;
	// }
	// free(tab);
}






// void			ft_put_solution(t_lem_in *env)
// {
// 	int			num;
// 	t_room		*tmp;

// 	num = 1;
// 	while (env->end->ant != env->nb_ant)
// 	{
// 		tmp = env->start;
// 		// ft_printf("tmp ant : %d, %d\n", tmp->ant, env->start->ant);
// 		if (env->start->ant > 0)
// 		{
// 			while (tmp->ant != 0)
// 			{
// 				if (tmp->id == env->start->id)
// 					tmp->ant--;
// 				else
// 				{
// 					tmp->ant++;
// 					ft_printf("L%d-%s ", tmp->ant - 1, tmp->name);
// 					num++;
// 				}

// 					tmp = tmp->path;
// 			}
// 			tmp->ant++;
// 		}
// 		else if (env->start->ant == 0)
// 		{
// 			while (tmp->ant == 0)
// 				tmp = tmp->path;
// 		}
// 		ft_printf("\n");
		// tmp = env->start->path;
		// if (tmp->ant == 0 && env->start->ant > 0)
		// {
		// 	env->start->ant--;
		// 	tmp->ant++;
		// }
		// else
		// {
		// 	while (tmp->ant != 0)
		// 	{

		// 		tmp = tmp->path;
		// 	}
		// }
	// }

	// while (frm >= 0)
	// {
	// 	// total = env->nb_ant;
	// 	env->room = env->start;
	// 	env->room = env->room->path;
	// 	total = env->nb_ant - frm;
	// 	while (total - frm > 0 && env->room)
	// 	{
	// 		ft_printf("L%d-%s ", total - frm, env->room->name);
	// 		if (env->room->path == NULL)
	// 			break ;
	// 		env->room = env->room->path;
	// 		total++;
	// 	}
	// 	ft_printf("\n");
	// 	frm--;
	// }



	// while (frm >= 0)
	// {
	// 	total = env->nb_ant;
	// 	env->room = env->start;
	// 	env->room = env->room->path;
	// 	while (total - frm > 0 && env->room)
	// 	{
	// 		ft_printf("L%d-%s ", total - frm, env->room->name);
	// 		if (env->room->path == NULL)
	// 			break ;
	// 		env->room = env->room->path;
	// 		total--;
	// 	}
	// 	ft_printf("\n");
	// 	frm--;
	// }

// }