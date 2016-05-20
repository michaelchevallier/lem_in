/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:35:48 by mchevall          #+#    #+#             */
/*   Updated: 2016/05/12 15:19:36 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(char *str)
{
	ft_putstr_fd("ERROR", 2);
	if (str)
	{
		ft_putchar_fd(' ', 2);
		ft_putstr_fd(str, 2);
	}
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}
