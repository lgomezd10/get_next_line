/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:18:02 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/04 18:01:39 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void			ft_delete_front(t_datalst *data)
{
	t_listc *delete;

	if (data && data->firts)
	{
		if (data->firts == data->last)
		{
			free(data->firts);
			data->firts = 0;
			data->last = 0;
		}
		else
		{
			delete = data->firts;
			data->firts = data->firts->next;
			free(delete);
		}
		data->len--;
	}
}

t_listc			*ft_new_elem(t_datalst *data)
{
	t_listc *new;

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
	if (!data->firts)
		data->firts = new;
	if (data->last)
		data->last->next = new;
	data->last = new;	
	data->len++;	
	return (new);
}

void			ft_list_clear(t_datalst *data)
{
	t_listc *rest;
	t_listc *elem;

	elem = data->firts;
	while (elem)
	{
		rest = elem->next;
		free(elem->str);
		free(elem);
		elem = rest;
	}
	data->firts = 0;
	data->last = 0;
	data->len = 0;
}

char *ft_strncpy(char *dest, char *src, int n)
{
	long i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	src[i] = '\0';
}
