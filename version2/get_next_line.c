/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:42:06 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/01 20:16:58 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_has_line_break(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char *ft_read_buffer(char **str, int fd)
{
	char *new;
	char *temp;
	int readed;
	
	while (!ft_has_line_break(str))
	{
		new = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (new)
		{
			readed = read(fd, readed, BUFFER_SIZE);
			new[readed] = '\0';
			temp = ft_join(*str, new);
			free(*str);
			free(new);
			str = &temp;
		}
		else
			return (0);		
	}
}

int		get_next_line(int fd, char **line)
{
	static char	*str = 0;
	static int		thereisline = -1;
	static int		end = 0;
	int				error;

	*line = 0;
	if (!(error = (fd < 0 || !line || BUFFER_SIZE <= 0)) && !end)
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
