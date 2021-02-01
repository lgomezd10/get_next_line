/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:18:02 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/01 18:54:37 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

unsigned int	ft_list_len(t_listc *list)
{
	unsigned int len;

	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}

void			ft_delete_front(t_listc **list)
{
	t_listc *delete;

	if (*list)
	{
		delete = *list;
		*list = delete->next;
		free(delete->str);
		free(delete);
	}
}

t_listc			*ft_new_elem(t_listc **list)
{
	t_listc *new;
	t_listc *last;

	new = (t_listc *)malloc(sizeof(t_listc));
	if (!new)
		return (0);
	new->str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new->str)
	{
		free(new);
		return (0);
	}
	new->next = 0;
	new->str[BUFFER_SIZE] = '\0';
	last = *list;
	if (!last)
		*list = new;
	else
	{
		while (last && last->next)
			last = last->next;
		last->next = new;
	}
	return (new);
}

void			ft_list_clear(t_listc **list)
{
	t_listc *rest;
	t_listc *elem;

	elem = *list;
	while (elem)
	{
		rest = elem->next;
		free(elem->str);
		free(elem);
		elem = rest;
	}
	*list = 0;
}