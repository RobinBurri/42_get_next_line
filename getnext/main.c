/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:39:24 by rburri            #+#    #+#             */
/*   Updated: 2021/11/05 09:56:02 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd;
	int close_ret;
	char *s = "";

	fd = open("alt_ln.txt", O_RDONLY);
	if (fd == -1 || !fd)
		{
			printf("Open Error\n");
			return (1);
		}
	
		while ((s = get_next_line(fd)) != NULL)
		{
			
			printf("%s", s);
			free(s);
		}
	close_ret = close(fd);
	if (close_ret == -1)
	{
		printf("Close Error\n");
		return (1);
	}
	// s = get_next_line(1);
	// printf("%s", s);
	// free(s);
	// while (1)
	// {}
}