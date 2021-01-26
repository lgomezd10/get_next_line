#include "get_next_line.h"

t_listc *ft_last_elem(t_listc *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

unsigned int ft_list_len(t_listc *list)
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

t_listc *ft_add_char(t_listc **list, char c)
{
	t_listc *new;
	t_listc *last;

	new = (t_listc *)malloc(sizeof(t_listc));
	if (!new)
		return (0);
	new->c = c;
	last = ft_last_elem(list);
	if (last)
		last->next = new;
	else
		*list = new;    
	return (*list);
}

void ft_list_clear(t_listc **list)
{
	t_listc *rest;
	t_listc *elem;
	
	elem = *list;
	while (elem)
	{
		rest = elem->next;
		free(elem);
		elem = rest;
	}
}

char *ft_list_to_str(t_listc *list)
{
    unsigned int len;
    unsigned int i;
    char *str;

    len = ft_list_len(list);
    len++;
    str = (char *)malloc(sizeof(char) * len);
    i = 0;
    while (list)
    {
        str[i] = list->c;
        list = list->next;
        i++;
    }
    str[i] = '\0';
}