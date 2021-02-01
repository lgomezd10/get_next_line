/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:56:52 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/01 20:16:58 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct	s_listc
{
	char			*str;
	struct s_listc	*next;
}				t_listc;

int				get_next_line(int fd, char **line);
char *ft_join(char *s1, char *s2);
unsigned long ft_strlen(char *s);

#endif
