/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 12:50:32 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/14 14:55:01 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

int		clean_open(const char *path, int flag)
{
	int		fd;

	fd = open(path, flag);
	if (fd == -1)
	{
		ft_putstr("open() error\nexiting program\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
