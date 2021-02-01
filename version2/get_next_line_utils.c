/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:18:02 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/01 20:16:58 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

unsigned long ft_strlen(char *s)
{
	unsigned long count;

	count = 0;
	while (s[count] != '0')
		count++;
	return (count);
}

char *ft_join(char *s1, char *s2)
{
	char *str;
	unsigned long i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str)
	{
		i = 0;
		while (s1[i] != '\0')
			*str++ = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			*str++ = s1[i++];
		*str = '\0';
	}
	return (str);
}
