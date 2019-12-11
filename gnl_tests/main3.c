#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*buffer;
	int		fd_read;
	int		continue_reading;
	int		i;

	fd = 0;
	fd_read = 1;
	continue_reading = 1;
	i = 0;
	buffer = "";
	if (argc == 1)
	{
		
		while(get_next_line(0, &buffer) > 0)
		{
			ft_putendl(buffer);
			free(buffer);
		}
	}
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{		
			fd = open(argv[i], O_RDONLY);
			while (get_next_line(fd, &buffer))
			{
				ft_putendl(buffer);
				free(buffer);
			}
			i++;
		}
	}
}