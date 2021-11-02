/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:13:17 by rburri            #+#    #+#             */
/*   Updated: 2021/11/01 18:33:03 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

#define BUFFER_SIZE 5

int        ft_check_newline(char *stack)
{
    int            i;

    i = 0;
    while (stack[i])
    {
        if (stack[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	max_len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) + 1)
		max_len = ft_strlen(s) + 1;
	else
		max_len = len;
	newstr = (char *)malloc(sizeof(char) * (max_len + 1));
	if (!newstr)
		return (NULL);
	while (start < ft_strlen(s) && i < max_len)
	{
		newstr[i] = s[start];
		i++;
		start++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s + 1);
	else
		return (0);
}


size_t	ft_strlen(const char *s)
{
	size_t len;
	
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*ret;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char *new_str;
	int len;
	int i;
	int j;

	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	new_str = (char *) malloc(len *sizeof(char));
	if (new_str == NULL)	
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] =s2[j++];
	new_str[i] = '\0';
	return (new_str);
}


/******************************************************/
char	*get_next_line(int fd)
{	
	char buf[BUFFER_SIZE + 1];
	static char *stack = "";
	char *line;
	int i;

	int ret;
	int check;
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
	 	buf[ret] ='\0';
		stack = ft_strjoin(stack, buf);
		while (ft_check_newline(stack) != -1)
		{
			i = 1;
			check = ft_check_newline(stack);
			if (check != -1)
			{
				line = ft_substr(stack, 0, check + 1);
				stack = ft_strchr(stack, 10);
				return (line);
			}
		}
	}
	return (stack);
		
}

/******************************************************/
int main()
{
	int fd;
	int close_ret;
	char *s;
	int end;

	end = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1 || !fd)
		{
			printf("Open Error");
			return (1);
		}
	
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
	close_ret = close(fd);
	if (close_ret == -1)
	{
		printf("Close Error");
		return (1);
	}
}