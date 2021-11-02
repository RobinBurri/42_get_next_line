/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 08:13:26 by rburri            #+#    #+#             */
/*   Updated: 2021/11/02 17:41:38 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define BUFFER_SIZE 11142

char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif