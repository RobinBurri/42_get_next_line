/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:13:17 by rburri            #+#    #+#             */
/*   Updated: 2021/11/02 16:32:33 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

static int	ft_check_newline(char *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{	
	char buf[BUFFER_SIZE + 1];
	static char *stack;
	char *line;
	int ret;
	int check;
	static int i = 0;

	if (i == 0)
	{
		stack = ft_strdup("");
		i = 1;
	}
	else
		stack = ft_strdup(stack);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
	 	buf[ret] ='\0';
		stack = ft_strjoin(stack, buf);
		while (ft_check_newline(stack) != -1)
		{
			check = ft_check_newline(stack);
			if (check != -1)
			{
				line = ft_substr(stack, 0, check + 1);
				stack = ft_strchr(stack, 10);
				return (line);
			}
		}
	}
	if (ft_strcmp(stack, "") == 0)
	{
		free(stack);
		return (NULL);
	}
	line = ft_strdup(stack);
	stack = ft_strdup("");
	return (line);
		
}
