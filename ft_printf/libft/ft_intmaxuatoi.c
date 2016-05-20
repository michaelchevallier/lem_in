/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxuatoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 16:02:05 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/06 16:32:27 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include <stdint.h>

intmax_t		ft_intmaxuatoi(const unsigned char *str)
{
	size_t				i;
	int					isneg;
	intmax_t			result;

	i = 0;
	result = 0;
	isneg = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ' || str[i] == '+')
	{
		i++;
		if ((str[i] == '+' || str[i] == '-') &&
				(str[i - 1] == '+' || str[i - 1] == '-'))
			return (result);
	}
	if (str[i] == '-' && (isneg = 1))
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return ((isneg == 1) ? -result : result);
}
