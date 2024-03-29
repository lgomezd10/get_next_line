/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:42:06 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/04 10:58:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_has_line_break(char *str)
{
	if (str)
	{
		while (*str != '\0')
		{
			if (*str == '\n')
				return (1);
			str++;
		}
	}
	return (0);
}

int ft_read_buffer(char **str, int fd)
{
	char *new;
	char *temp;
	int readed;
	int out;
	
	out = 0;
	while (!ft_has_line_break(*str) && out == 0)
	{
		out = -1;
		new = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (new)
		{
			readed = read(fd, new, BUFFER_SIZE);
			if (readed != -1)
			{
				new[readed] = '\0';
				temp = ft_join(*str, new);
				out = (temp && readed >= 0) ? 0 : out;
				free(*str);
				*str = temp;
			}
			free(new);
			out = (readed < BUFFER_SIZE) ? 1 : out;
		}		
	}
	return (out);
}

char	*ft_get_line(char *str)
{
	unsigned long i;
	char *line;

	if (str)
	{
		i = ft_strlen_to(str, '\n');
		if (!i)
			i = ft_strlen_to(str, '\0');
		line = (char *)malloc(sizeof(char) * i);
		if (line)
		{
			line = ft_strcpy(line, str, i - 1);
			str = ft_strcpy(str, &str[i], ft_strlen_to(&str[i], '\0'));
			return (line);
		}
	}
	return (0);	
}

int		get_next_line(int fd, char **line)
{
	static char	*str = 0;
	int			end;
	int			error;	

	*line = 0;
	end = 0;
	if (!(error = (fd < 0 || !line || BUFFER_SIZE <= 0)))
	{
		if (!ft_has_line_break(str))
			end = ft_read_buffer(&str, fd);
	}
	end = (end == 1 && ft_has_line_break(str)) ? 0 : end;
	if (error || end == -1 || !(*line = ft_get_line(str)))
	{
		free(str);
		str = 0;
		return (-1);
	}
	if (end)
	{		
		free(str);
		str = 0;
		return (0);
	}
	return (1);
}
