/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 11:31:14 by mchevall          #+#    #+#             */
/*   Updated: 2016/02/16 13:29:28 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int		line_cutter(char **remain, int len, char **line, int ret)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*remain)[i] != '\0' && (*remain)[i] != '\n')
	{
		if (++i == len && ret == 0)
		{
			*line = ft_strsub(*remain, 0, i);
			tmp = *remain;
			*remain = ft_strsub(*remain, i + 1, len);
			len = ft_strlen(*remain);
			ft_strdel(&tmp);
			return (-1);
		}
	}
	if ((i <= len && (*remain)[i] == '\n'))
	{
		*line = ft_strsub(*remain, 0, i);
		tmp = *remain;
		*remain = ft_strsub(*remain, i + 1, len);
		ft_strdel(&tmp);
		return (-1);
	}
	return (i);
}

static int		line_manager(char *buf, char **remain, char **line, int ret)
{
	size_t			i;
	char			*tmp;
	size_t			len;

	i = 0;
	if (*remain)
	{
		tmp = *remain;
		*remain = ft_strjoin(*remain, buf);
		ft_strdel(&tmp);
	}
	else
		*remain = ft_strdup(buf);
	len = ft_strlen(*remain);
	if (line_cutter(remain, len, line, ret) == -1)
		return (-1);
	if (ret == 0 && len == 0)
	{
		ft_strdel(remain);
		return (0);
	}
	return (i);
}

int				get_next_line(int const fd, char **line)
{
	static char		*remain;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	int				checkline;

	checkline = 0;
	if (!line)
		return (-1);
	while (checkline != -1)
	{
		ret = clean_read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (ret);
		buf[ret] = '\0';
		checkline = line_manager(buf, &remain, line, ret);
		if (checkline == 0 && remain == NULL && ret == 0)
			return (0);
	}
	return (1);
}
