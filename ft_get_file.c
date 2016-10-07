/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:55:03 by quroulon          #+#    #+#             */
/*   Updated: 2016/10/07 16:07:43 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_file_empty_line(char **file)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = *file;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			i++;
			if (tmp[i] && tmp[i] == '\n')
			{
				(*file) = ft_strsub(tmp, 0, i);
				ft_strdel(&tmp);
				break ;
			}
		}
		i++;
	}
}

void			ft_scd_part_file(char **tab, char **file, int i)
{
	int			j;
	int			cpt;
	char		*tmp;

	tmp = *file;
	while (tab[i])
	{
		cpt = 0;
		j = 0;
		if (tab[i][0] != '#')
		{
			while (tab[i][j])
			{
				if (tab[i][j] == '-')
					cpt++;
				j++;
			}
			if (cpt != 1)
				break ;
		}
		i++;
	}
	j = 0;
	while ((*file)[j])
	{
		if ((*file)[j] == '\n')
			i--;
		if (i == 0)
			break ;
		j++;
	}
	(*file) = ft_strsub(tmp, 0, j);
	ft_strdel(&tmp);
}

void			ft_sort_file(char **file, t_lem_in *env)
{
	int			i;
	int			j;
	int			cpt;
	char		**tab;

	i = 0;
	j = 0;
	tab = ft_strsplit(*file, '\n');
	while (tab[i])
	{
		cpt = 0;
		j = 0;
		while (tab[i][j] && tab[i][0] != '#')
		{
			if (tab[i][j] == ' ')
			{
				j++;
				if (ft_isdigit(tab[i][j]) == 0)
				{
					ft_printf("Le fichier est mal formaté, ligne %d", i + 1);
					ft_dbstrdel(tab);
					ft_error_lem_in("\0", env);
				}
				cpt++;
			}
			if (tab[i][j] == '-' && tab[i][0] != '#' && i != 0)
			{
				ft_scd_part_file(tab, file, i);
				ft_dbstrdel(tab);
				return ;
			}
			j++;
		}
		if (cpt != 2 && tab[i][0] != '#' && i != 0)
		{
			ft_dbstrdel(tab);
			ft_error_lem_in(NULL, env);
		}
		i++;
	}
	ft_dbstrdel(tab);
}

// void			ft_verif_begin(char *file, t_lem_in *env, int *verif)
// {
// 	int			i;
// 	int			j;

// 	i = 0;
// 	j = 0;
// 	(*verif)++;
// 	while (file[i] && file[i] != '\n')
// 	{
// 		if (file[i] == '#')
// 		{
// 			while (file[i] != EOF && file[i] != '\n')
// 				i++;
// 			if (file[i] == '\n')
// 				i++;
// 			else
// 				ft_error_lem_in(NULL, env);
// 		}
// 		else if (ft_isdigit(file[i]) == 1)
// 			i++;
// 		else if (file[i] == '\n')
// 			break ;
// 		else if (ft_isdigit(file[i]) == 0 && file[i] != '\n')
// 			ft_error_lem_in(NULL, env);
// 	}
// }

// void			ft_get_file(char **file, t_lem_in *env, int verif)
// {
// 	int			fd;
// 	char		*buf;
// 	char		*tmp;

// 	buf = ft_strnew(BUFF_READ);
// 	*file = ft_strnew(0);
// 	fd = 0;
// 	while (read(fd, buf, BUFF_READ) > 0)
// 	{
// 		tmp = *file;
// 		*file = ft_strjoin(tmp, buf);
// 		ft_strdel(&tmp);
// 		ft_strdel(&buf);
// 		if (verif == 0)
// 			ft_verif_begin(*file, env, &verif);
// 		else
// 			verif++;
// 		buf = ft_strnew(BUFF_READ);
// 	}
// 	ft_strdel(&buf);
// 	ft_file_empty_line(file);
// 	ft_sort_file(file, env);
// }

void			ft_get_file(char **file, t_lem_in *env)
{
	int			i;
	char		*line;
	char		*tmp;

	i = 0;
	line = NULL;
	tmp = NULL;
	while ((i = get_next_line(0, &line)) > 0)
	{
		if (*file == NULL)
			*file = ft_strnew(0);
		tmp = *file;
		*file = ft_strjoin(tmp, line);
		ft_strdel(&tmp);
		ft_strdel(&line);
		tmp = *file;
		*file = ft_strjoin(tmp, "\n");
		ft_strdel(&tmp);
	}
	ft_strdel(&line);

	env->nb_ant = 0;
}

// int				ft_hashtag_bis(int j, int *i, char *file, t_lem_in *env)
// {
// 	char		*tmp;

// 	tmp = NULL;
// 	if (file[(*i)] == '#' && (*i)++)
// 	{
// 		env->tmp = 0;
// 		while (file[*i] != '\0' && file[*i] != '\n' && (*i)++)
// 			env->tmp++;
// 		tmp = ft_strsub(file, (*i) - env->tmp, env->tmp);
// 		if (ft_strcmp(tmp, "start") == 0 && env->t_start == 0)
// 		{
// 			env->t_start = 1;
// 			(*i)++;
// 			j++;
// 		}
// 		else if (ft_strcmp(tmp, "end") == 0 && env->t_end == 0)
// 		{
// 			env->t_end = 1;
// 			(*i)++;
// 			j++;
// 		}
// 		else
// 			(*i)++;
// 		ft_strdel(&tmp);
// 	}
// 	else
// 	{
// 		while (file[*i] != '\0' && file[*i] != '\n')
// 			(*i)++;
// 		(*i)++;
// 	}
// 	return (j);
// }
