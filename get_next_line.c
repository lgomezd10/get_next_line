/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:42:06 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/01/28 13:17:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_has_line_break(t_listc *elem)
{
	int		i;
	char	*str;

	if (elem)
	{
		str = elem->str;
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
	}
	return (0);
}

void	ft_delete_to_line_break(t_listc *elem)
{
	int		i;
	int		j;
	char	*str;

	str = elem->str;
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		i++;
		j = 0;
		while (str[i] != '\0')
			str[j++] = str[i++];
		str[j] = '\0';
	}
	printf("después de borrar: %s\n", elem->str);
}

char	*ft_get_line(t_listc **list, int pos)
{
	int		i;
	char	*str;
	char	*result;
	t_listc	*elem;

	
	elem = *list;
	printf("entrando en getline: %s\n", elem->str);
	i = (ft_list_len(elem) - 1) * BUFFER_SIZE;
	str = (char *)malloc(sizeof(char) * (i + pos + 2));
	if ((result = str))
	{
		while (elem)
		{
			printf("leyendo\n");
			i = 0;
			while (elem->str[i] != '\n' && elem->str[i] != '\0')
				*str++ = elem->str[i++];
			*str = '\0';
			if (elem->str[i] != '\n')
				ft_delete_front(list);
			else
				ft_delete_to_line_break(*list);
			elem = (elem) ? elem->next : 0;
		}
	}
	printf("Linea leida: %s\n", result);
	return (result);
}

int		ft_read_fd(int fd, t_listc **list, int *thereisline)
{
	t_listc	*elem;
	int		end;
	int		readed;

	end = 0;
	while (!*thereisline && !end)
	{
		elem = ft_new_elem(list);
		printf("longitud de list: %d\n", ft_list_len(*list));
		if (!elem)
			return (-1);
		readed = read(fd, elem->str, BUFFER_SIZE);
		if (readed < BUFFER_SIZE)
			end = readed;
		elem->str[readed] = '\0';
		*thereisline = ft_has_line_break(elem);
		printf("thereisline %d, elem: %s\n", *thereisline, elem->str);
	}
	return (end);
}

int		get_next_line(int fd, char **line)
{
	static t_listc	*list = 0;
	static int		thereisline = 0;
	static int		end = 0;
	int				error;

	if (!(error = fd < 0 || !line || BUFFER_SIZE <= 0))
	{
		if (end && !thereisline)
		{
			ft_list_clear(&list);
			*line = 0;
			return (0);
		}
		if (!thereisline && !end)
			if ((end = ft_read_fd(fd, &list, &thereisline)) == -1)
				error = 1;
	}
	if (error || !(*line = ft_get_line(&list, thereisline)))
	{
		ft_list_clear(&list);
		return (-1);
	}
	if ((!ft_has_line_break(list) && !end) || (end && !list))
		thereisline = 0;
	return (1);
}
