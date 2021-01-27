/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:42:06 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/01/27 20:18:47 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void ft_delete_to_line_break(t_listc *elem)
{
    int i;
    int j;
    char *str;

    str = elem->str;
    i = 0;
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    if (str[i] != '\n')
    {
        j = 0;
        while (str[i] != '\0')
            str[j++] = str[i++];
        str[j] = '\0';
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
        while (elem)
        {
            i = 0;
            while (elem->str[i] != '\n' && elem->str[i] != '\0')
            {
                *str = elem->str[i++];
                str++;                
            }
            if (elem->next && elem->str[i] != '\n')
                ft_delete_front(list);
            else
                ft_delete_to_line_break(*list);            
            elem = elem->next;
        }
    }
    return (str);
}

int ft_read_fd(int fd, t_listc **list, int *thereisline)
{
    t_listc *elem;
    int break_line;
    int end;
    int readed;

    break_line = 0;
    end = 0;
    while (!break_line && !end)
    {
        elem = ft_new_elem(list);
        if (!elem)
            return (-1);
        readed = read(fd, elem->str, BUFFER_SIZE);
        if (readed < BUFFER_SIZE)
            end = 1;
        elem->str[readed] = '\0';
        *thereisline = ft_has_line_break(elem);        
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