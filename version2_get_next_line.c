/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:42:06 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/01/28 09:20:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int ft_has_line_break(t_listc *elem)
{
	int     i;
	char    *str;

	str = elem->str;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}


char *ft_strcpy(char *dest, char *src, int n)
{
	int i;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void ft_delete_to_line_break(t_listc *elem)
{
	int i;
	int j;
	char *str;

	str = elem->str;
	if (j = ft_has_line_break(elem))
	{
		i = 0;
		ft_strcpy(str[i], str[j], BUFFER_SIZE);
	}	
}

char *ft_get_line(t_listc **list, int pos)
{    
	int len;
	int i;
	char *str;
	t_listc *elem;

	elem = *list;
	len = (ft_list_len(elem) - 1) * BUFFER_SIZE;
	str = (char *)malloc(sizeof(char) * (len + pos + 2));
	if (str)
	{
		i = 0;
		while (elem)
		{
			if (pos = ft_has_line_break(elem))
			{
				ft_strcpy(str[i], elem->str, pos);
				ft_delete_to_line_break(elem);
				return (str);
			}
			else
			{
				ft_strcpy(str[i], elem->str, BUFFER_SIZE);
				elem = elem->next;
				ft_delete_front(*list);
				i += BUFFER_SIZE; 
			}
		}
	}
	return (str);
}

int ft_read_fd(int fd, t_listc **list, int *thereisline)
{
	t_listc *elem;
	int end;
	int readed;

	end = 0;
	while (!*thereisline && !end)
	{
		elem = ft_new_elem(list);
		if (!elem)
			return (-1);
		readed = read(fd, elem->str, BUFFER_SIZE);
		if (readed < BUFFER_SIZE)
			end = 1;
		elem->str[readed] = '\0';
		*thereisline = ft_has_line_break(elem);
		printf("hay thereisline: %d end: %d\n", *thereisline, end);
	}
	if (end)
		return (0);
	return (1);
}

int get_next_line(int fd, char **line)
{    
	static t_listc *list = 0;
	static int thereisline = 0;
	int readed;
	int end;
	int result;
	
	end = 0;
	if (!thereisline)
		end = ft_read_fd(fd, &list, &thereisline);
		if (end == -1)
		{
			ft_list_clear(&list);
			return (-1);
		}
	*line = ft_get_line(&list, thereisline);
	if (!*line)
	{
		ft_list_clear(&list);
			return (-1);
	}
	if (!ft_has_line_break(list))
		thereisline = 0;
	if (end)
	{
		ft_list_clear(&list);
		return (0);
	}
	return (1);
}