/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 19:39:07 by quroulon          #+#    #+#             */
/*   Updated: 2016/10/03 19:54:59 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_hash(char *word)
{
	int			cpt;
	int			hashAddress;

	hashAddress = 5381;
	cpt = 0;
	while (word[cpt] != '\0')
	{
	    hashAddress = ((hashAddress << 5) + hashAddress) + word[cpt];
		cpt++;
	}
	return (hashAddress);
}