/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:42:29 by quroulon          #+#    #+#             */
/*   Updated: 2016/07/01 18:33:56 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int				main(void)
{
	int		fd;
	char	*str;

	str = NULL;
	fd = 0;
	// fd = open(0, O_RDONLY);
	if (fd != -1)
	{
		while (get_next_line(fd, &str) > 0)
		{
			ft_printf("%s\n", str);
		}
	}
	ft_strdel(&str);
	return (0);
}
