/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:59:53 by rburri            #+#    #+#             */
/*   Updated: 2021/11/02 15:42:55 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
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
	char	*new_str;
	int		len;
	int		i;
	int		j;

	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	new_str = (char *)malloc(len *sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}
