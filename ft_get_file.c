/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:55:03 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/28 19:08:23 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_hashtag_bis(int j, int *i, char *file, t_lem_in *env)
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
		{
			env->t_start = 1;
			(*i)++;
			j++;
		}
		else if (ft_strcmp(tmp, "end") == 0 && env->t_end == 0)
		{
			env->t_end = 1;
			(*i)++;
			j++;
		}
		else
			(*i)++;
		ft_strdel(&tmp);
	}
	else
	{
		while (file[*i] != '\0' && file[*i] != '\n')
			(*i)++;
		(*i)++;
	}
	return (j);
}

void			ft_verif_begin(char *file, t_lem_in *env, int *verif)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (file[i] || file[i] != '\n')
	{
		if (file[i] == '#')
		{
			(*verif) = 0;
			i++;
			if (ft_hashtag_bis(0, &i, file, env) > 0)
				ft_error_lem_in(NULL, env);
			i--;
		}
		else if (ft_isdigit(file[i]) == 0)
		{
			(*verif)++;
			ft_error_lem_in(NULL, env);
		}
		i++;
	}
}

void			ft_get_file(char **file, t_lem_in *env, int verif)
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
		if (verif == 0)
			ft_verif_begin(*file, env, &verif);
		else
			verif++;
		buf = ft_strnew(BUFF_READ);
	}
	ft_strdel(&buf);
}
