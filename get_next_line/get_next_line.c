/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:42:06 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/03 18:48:33 by lgomez-d         ###   ########.fr       */
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

char	*ft_quit_line(char *str)
{
	int i;

	i = ft_strlen_to(str, '\n');
	str = ft_strcpy(str, &str[i], ft_strlen_to(&str[i], '\0'));
	return (str);
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
			//str = ft_strcpy(str, &str[i], BUFFER_SIZE);
			return (line);
		}
	}
	return (0);	
}

int		get_next_line(int fd, char **line)
{
	static char	*str = 0;
	static int		end = 0;
	int				error;	

	*line = 0;
	if (!(error = (fd < 0 || !line || BUFFER_SIZE <= 0 || (end == 1 && !str))))
	{
		if (!ft_has_line_break(str) && !end)
			end = ft_read_buffer(&str, fd);
	}
	if (error || end == -1 || !(*line = ft_get_line(str)))
	{
		free(str);
		str = 0;
		return (-1);
	}
	//printf("End: %d str: %sFIN\nhasretur: %d", end, str, ft_has_line_break(str));
	if (end && !ft_has_line_break(str))
	{	
		free(str);
		str = 0;
		return (0);
	}
	ft_quit_line(str);
	
	return (1);
}
