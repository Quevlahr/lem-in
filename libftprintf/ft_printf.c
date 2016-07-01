/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:37:04 by quroulon          #+#    #+#             */
/*   Updated: 2016/06/03 16:30:37 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_read(const char *format, int i, t_env *env, va_list ap)
{
	env->nb_arg = 0;
	env->nb_char = 0;
	while (format[i])
	{
		if (format[i] == '%' && env->nb_char >= 0)
		{
			i++;
			ft_initflag(format, env, &i);
			ft_initconv(&i, env, ap);
		}
		else if (env->nb_char >= 0)
		{
			env->nb_char++;
			ft_putchar(format[i]);
			i++;
		}
		else
			i++;
	}
}

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	t_env			env;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	env.str = format;
	ft_read(format, 0, &env, ap);
	return (env.nb_char);
}
