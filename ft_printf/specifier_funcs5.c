/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_funcs5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:00:40 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/13 15:09:39 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			spec_b(t_var *var)
{
	if (var->mod_len != 0)
		return ((var->error = -1));
	else
	{
		var->arg = ft_itoa_baseuint((uintmax_t)var->arg, 2);
	}
	return (var->spec_len = ft_strlen(var->arg));
}
