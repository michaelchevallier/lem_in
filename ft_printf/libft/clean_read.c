/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:52:33 by mchevall          #+#    #+#             */
/*   Updated: 2015/12/18 15:56:18 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int		clean_read(int fildes, char *buf, size_t nbyte)
{
	int	ret;

	ret = read(fildes, buf, nbyte);
	if (ret == -1)
	{
		ft_putstr("read() error\n exiting program\n");
		exit(EXIT_FAILURE);
	}
	buf[ret] = '\0';
	return (ret);
}
