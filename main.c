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
	buffer = ft_strdup("nothing");
	if (argc == 1)
	{
		
		while(fd_read >= 0 && ft_strequ(buffer, "quit") != 1)
		{
			ft_putstr("insert text: ");
			fd_read = get_next_line(0, &buffer);
			ft_putstr("you inserted: ");
			ft_putendl(buffer);
		}
	}
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{ 
			fd = open(argv[i], O_RDONLY);
		//while (continue_reading)
		//{
			//ft_putstr("to continue reading, press enter. to quit, write quit.");
			//fd_read = get_next_line(0, &buffer);
			//if (ft_strequ(buffer, "quit"))
			//	return (1);
			//else if (ft_strequ(buffer, "\n")
			//{
				while (fd_read > 0)
				{
					fd_read = get_next_line(fd, &buffer);
					ft_putendl(buffer);
				}
			//}
		//}
		i++;
		}
	}
}