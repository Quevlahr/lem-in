/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_room2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 19:10:19 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/21 18:24:27 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_hashtag_end(t_lem_in *env, int *i)
{
	env->t_end = 1;
	(*i)++;
}

static void		ft_hashtag_start(t_lem_in *env, int *i)
{
	env->t_start = 1;
	(*i)++;
}

static void		ft_hashtag_comment(char *file, int *i)
{
	while (file[*i] != '\0' && file[*i] != '\n')
		(*i)++;
	(*i)++;
}

int				ft_hashtag(int *i, char *file, t_lem_in *env)
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
			ft_hashtag_start(env, i);
		else if (ft_strcmp(tmp, "end") == 0 && env->t_end == 0)
			ft_hashtag_end(env, i);
		else if (ft_strcmp(tmp, "end") == 0 || ft_strcmp(tmp, "start") == 0)
			ft_error_lem_in_start(DOUBLE_CMD, tmp, env);
		else
			(*i)++;
		ft_strdel(&tmp);
	}
	else
		ft_hashtag_comment(file, i);
	return (1);
}
