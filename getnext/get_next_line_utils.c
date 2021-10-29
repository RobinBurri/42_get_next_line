/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:59:53 by rburri            #+#    #+#             */
/*   Updated: 2021/10/29 13:43:31 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;
	
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char *s2;
	size_t size;
	int i;

	size = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * size + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_empty_str(int a)
{	
	char	*s;
	int		i;
	s = (char *)malloc(a);
	i = 0;
	while (i < a)
	{
		s[i] = '\0';
	}
	return (s);
}

void	ft_strcat(char *dest, char *src)
{
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(dest);
	while (src[i])
		dest[l++] = src[i++];
	return ;
}

void	ft_check_eof_eol(char *s, int *eof, int *eol)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == EOF)
			*eof = 0;
		else if (s[i] == '\n')
			*eol = 0;
		i++;
	}	
	return ;
}