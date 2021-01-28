/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:56:52 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/01/28 12:28:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct  s_listc
{
	char    *str;
	struct s_listc *next;
}	t_listc;

int get_next_line(int fd, char **line);
t_listc *ft_last_elem(t_listc *list);
unsigned int ft_list_len(t_listc *list);
t_listc *ft_new_elem(t_listc **list);
void ft_list_clear(t_listc **list);
char *ft_list_to_str(t_listc *list);
void ft_delete_front(t_listc **list);

#endif