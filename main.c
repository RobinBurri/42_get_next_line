#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd;
	int close_ret;
	char *s;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1 || !fd)
		{
			printf("Open Error");
			return (1);
		}
	s = get_next_line(fd);
	printf("%s", s);
	close_ret = close(fd);
	if (close_ret == -1 || !close_ret)
	{
		printf("Close Error");
		return (1);
	}
}