/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:39:19 by mchevall          #+#    #+#             */
/*   Updated: 2015/12/08 18:48:38 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		if (content == NULL)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else
		{
			new->content = malloc(content_size);
			if (!new->content)
				return (NULL);
			new->content = ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
		}
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
