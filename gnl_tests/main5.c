#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int				main(void)
{
	char		*line = NULL;
	int			fd = open("test5", O_RDONLY);

	get_next_line(fd, &line);
	close(fd);
	while(1);
	return (0);
}