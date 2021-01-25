#include "get_next_line.h"

t_listc *last_elem(t_listc *list)
{
    while (list && list->next)
        list = list->next;
    return (list);
}

t_listc *add_char(t_listc *list, char c)
{
    t_listc *new;
    t_listc *last;

    new = (t_listc *)malloc(sizeof(t_listc));
    if (!new)
        return (0);
    new->c = c;
    last = last_elem(list);
    last->next = new;
    return (list);
}