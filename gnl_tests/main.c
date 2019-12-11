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
		
		while(ft_strequ(buffer, "quit") != 1)
		{
			ft_putstr("insert text: ");
			fd_read = get_next_line(0, &buffer);
			ft_putstr("you inserted: ");
			ft_putendl(buffer);
			free(buffer);
		}
		while (1);
	}
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
			while (fd_read > 0)
			{
				ft_putstr("to continue reading, write yes. to quit, write quit. ");
				fd_read = get_next_line(0, &buffer);
				if (ft_strequ(buffer, "quit"))
				{	
					free(buffer);
					while (1);
				}
				else if (ft_strequ(buffer, "yes"))
				{
					//ft_putendl("inside else");
					free(buffer);
					fd_read = get_next_line(fd, &buffer);
					if (fd_read == -1)
					{
						ft_putendl ("error while reading the input");
						free(buffer);
						return (-1);
					}
					ft_putendl("wtf2");
					ft_putstr(buffer);
					ft_putchar('\n');
					ft_putendl("wtf2");
					//if (fd_read > 0)
						free(buffer);
				}
			}
			while (1);
	}
	if (argc > 2)
	{
		i = 1;
		ft_putstr("these fds opened: ");
		while (i < argc)
		{		
			fd = open(argv[i], O_RDONLY);
			ft_putnbr(fd);
			ft_putstr(", ");
			i++;
		}
		while (1)
		{
			ft_putchar('\n');
			ft_putstr("Insert the fd from where you want to read. to quit, write quit. ");
			fd_read = get_next_line(0, &buffer);
			int int_buffer = 1;
			int w = 0;
			while (buffer[w] != '\0')
			{
				if (ft_isdigit(buffer[w]) == 0)
					int_buffer = -1;
				w++;
			}
			if (ft_strequ(buffer, "quit"))
			{	
				free(buffer);
				while(1)
				{}
			}
			else if (int_buffer != 1)
				ft_putendl("string you entered is not a number");
			else if (int_buffer == 1)
			{
				fd = ft_atoi(buffer);
				free(buffer);
				fd_read = get_next_line(fd, &buffer);
				if (fd_read == -1)
				{
					ft_putendl ("error while reading the input");
					return (-1);
				}
				if (fd_read == 0)
				{
					ft_putstr("EOF reached for fd ");
					ft_putnbr(fd);
					ft_putchar('.');
					ft_putchar('\n');
				}
				else 
				{
					ft_putstr(buffer);
					//ft_putchar('\n');
				}
			free(buffer);
			}
		}
		while (1);
	}
}