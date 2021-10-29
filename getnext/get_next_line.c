/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:13:17 by rburri            #+#    #+#             */
/*   Updated: 2021/10/29 15:25:33 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

#define BUFFER_SIZE 5

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
		s[i++] = '\0';
	return (s);
}

void	ft_strlcat(char *dest, char *src, int l)
{
	int	x;
	int	i;

	i = 0;
	x = ft_strlen(dest);
	while (src[i] && src[i] != '\03' && i < l)
		dest[x++] = src[i++];
}

int	ft_check_eof_eol(char *s, int *eof, int *eol)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == EOF)
		{
			*eof = 0;
			return (i + 1);
		}
		else if (s[i] == '\n')
		{
			*eol = 0;
			return (i + 1);
		}
		i++;
	}	
	return (i + 1);
}
/******************************************************/
char	*get_next_line(int fd)
{	
	char buf[BUFFER_SIZE];
	char *s;
	int ret;
	int eof;
	int eol;
	int len;

	eof = 1;
	eol = 1;
	s = ft_empty_str(10);
	while (eof == 1 && eol == 1)
	{
		ret = 0;
		ret = read(fd, buf, BUFFER_SIZE);
		if (!ret || ret == 0)
			return (NULL);
		len = ft_check_eof_eol(buf, &eof, &eol);
		ft_strlcat(s, buf, len);
	}
	if (len < ret)
	{
		
	}	
		
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
	while (end == 0)
	{
		s = get_next_line(fd);
		printf("%s", s);
		if (s == NULL)
			end = 1;
	}
	free(s);
	close_ret = close(fd);
	if (close_ret == -1)
	{
		printf("Close Error");
		return (1);
	}
}