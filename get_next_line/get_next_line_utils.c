/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:18:02 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/02 12:27:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

unsigned long ft_strlen_to(char *str, char c)
{
	unsigned long count;

	if (str)
	{
		count = 0;
		while (str[count] != c && str[count] != '\0')
			count++;
		if (str[count] == c)
			return (count + 1);
	}
	return (0);
}

char *ft_strcpy(char *dest, char *src, unsigned long n)
{
	unsigned long i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_join(char *s1, char *s2)
{
	char *str;
	unsigned long i;
	unsigned long j;

	i = ft_strlen_to(s1, '\0') - 1 + ft_strlen_to(s2, '\0');
	str = (char *)malloc(sizeof(char) * i);
	if (str)
	{
		i = 0;
		j = 0;
		while (s1 && s1[i] != '\0')
			str[j++] = s1[i++];
		i = 0;
		while (s2 && s2[i] != '\0')
			str[j++] = s2[i++];
		str[j] = '\0';
	}
	return (str);
}
