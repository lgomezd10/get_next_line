#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    char c;
    t_listc *list;
    char *str;

    c = '\0';
    list = 0;
    while (read(fd, &c, 1) && c != '\n')
    {
        if (!ft_add_char(&list, c))
        {
            ft_list_clear(&list);
            return (-1);
        }            
    }
    if (ft_list_len(list))
    {
        str = ft_list_to_str(list);
        ft_list_clear(&list);
        if (!str)
            return (-1);
    }
    if (c == '\n')
        return (1);
    else
        return (0);    
}