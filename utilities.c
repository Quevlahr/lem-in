/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:37:18 by quroulon          #+#    #+#             */
/*   Updated: 2016/07/18 18:57:28 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_error_lem_in(char *str)
{
	if (str != NULL)
		ft_printf("%s\n", str);
	else
		ft_printf("ERROR\n");
	exit(EXIT_FAILURE);
}