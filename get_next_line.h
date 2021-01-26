/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:56:52 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/01/26 09:39:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct  s_listc
{
	char    c;
	struct s_listc *next;
}	t_listc;

t_listc *ft_last_elem(t_listc *list);
unsigned int ft_list_len(t_listc *list);
t_listc *ft_add_char(t_listc **list, char c);
void ft_list_clear(t_listc **list);
char *ft_list_to_str(t_listc *list);
#endif