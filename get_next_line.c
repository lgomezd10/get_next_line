/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:42:06 by lgomez-d          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/02/01 18:53:17 by lgomez-d         ###   ########.fr       */
=======
/*   Updated: 2021/01/29 09:37:18 by user42           ###   ########.fr       */
>>>>>>> b64a22103af9962f132f57f530ddf62d55bc8071
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
	return (-1);
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
}

char	*ft_get_line(t_listc **list, int pos)
{
	int		i;
	char	*str;
	char	*result;
	t_listc	*elem;

	elem = *list;
	i = (ft_list_len(elem) - 1) * BUFFER_SIZE;
	str = (char *)malloc(sizeof(char) * (i + pos + 2));
	if ((result = str))
	{
		while (elem)
		{
			i = 0;
			while (elem->str[i] != '\n' && elem->str[i] != '\0')
				*str++ = elem->str[i++];
			*str = '\0';
			elem = (elem) ? elem->next : 0;
			if ((*list)->str[i] != '\n' || BUFFER_SIZE == 1)
				ft_delete_front(list);
			else
				ft_delete_to_line_break(*list);
		}
	}
	return (result);
}

int		ft_read_fd(int fd, t_listc **list, int *thereisline)
{
	t_listc	*elem;
	int		end;
	int		readed;

	end = 0;
	while (*thereisline < 0 && !end)
	{
		elem = ft_new_elem(list);
		if (!elem)
			return (-1);
		readed = read(fd, elem->str, BUFFER_SIZE);
		if (readed == -1)		
			return (-1);
		if (readed < BUFFER_SIZE)
			end = (readed == 0) ? 1 : readed;
		elem->str[readed] = '\0';
		*thereisline = ft_has_line_break(elem);
	}
	return (end);
}

int		get_next_line(int fd, char **line)
{
	static t_listc	*list = 0;
	static int		thereisline = -1;
	static int		end = 0;
	int				error;

	*line = 0;
<<<<<<< HEAD
	if (!(error = (fd < 0 || !line || BUFFER_SIZE <= 0)) && !end)
=======
	if (!(error = (fd < 0 || !line || BUFFER_SIZE <= 0)))
>>>>>>> b64a22103af9962f132f57f530ddf62d55bc8071
	{
		if (thereisline < 0 && !end)
			if ((end = ft_read_fd(fd, &list, &thereisline)) == -1)
				error = 1;
	}
	if (error || !(*line = ft_get_line(&list, thereisline)))
	{
		ft_list_clear(&list);
		return (-1);
	}
	if (end && !list)
	{
		ft_list_clear(&list);
		return (0);
	}
	if ((ft_has_line_break(list) == -1 && !end) || (end && !list))
		thereisline = -1;
	return (1);
}
