/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:42:29 by quroulon          #+#    #+#             */
/*   Updated: 2016/09/12 10:08:01 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_get_file(char **file)
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
		buf = ft_strnew(BUFF_READ);
	}
	ft_strdel(&buf);
}

int				ft_nb_ants(char *file)
{
	int			i;

	i = 0;
	while (ft_isdigit(file[i]) == 1)
		i++;
	while (file[i] == '\t' || file[i] == ' ')
		i++;
	if (file[i] == '\n')
	{
		i = ft_atoi(file);
		return (i);
	}
	else
		ft_error_lem_in("Le nombre de fourmis est manquant ou au mauvais format");
	return (0);
}

int				main(void)
{
	char		*file;
	t_lem_in	*env;

	env = (t_lem_in*)malloc(sizeof (t_lem_in));
	file = NULL;
	ft_get_file(&file);
	env->nb_ant = ft_nb_ants(file);
	ft_printf("%d\n", env->nb_ant);
	return (0);
}
