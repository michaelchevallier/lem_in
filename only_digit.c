/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_digit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:53:49 by mchevall          #+#    #+#             */
/*   Updated: 2016/05/19 14:31:15 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				only_digit(char *file)
{
	int			i;
	static int k;

	k++;

	i = 0;
	if (file[i] == '+')
			i++;
	while (file[i])
	{
		if (ft_isdigit(file[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
