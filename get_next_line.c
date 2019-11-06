#include "get_next_line.h"

void		ft_dynamic_string(char **dest, char *src, int num)
{
	char	*returnable;
	char	*temp_src;

	temp_src = ft_strnew(num + 1);
	temp_src = memcpy(temp_src, src, num);
	temp_src[num] = '\0';
	if (!*dest)
		*dest = ft_strdup(temp_src);
	else
	{
		returnable = ft_strjoin(*dest, temp_src);
		*dest = ft_strdup(returnable);

	}
	return;
}

int		get_next_line(const int fd, char **line)
{
	int		bytes_read;
	char	*buffer;
	char	*all_data;

	all_data = NULL;
	buffer = ft_strnew(BUFF_SIZE);
	bytes_read = read(fd, buffer, BUFF_SIZE);
	ft_dynamic_string(&all_data, buffer, bytes_read);
	while (bytes_read == BUFF_SIZE)
	{
		if (fd == 0 && buffer[BUFF_SIZE - 1] == '\n')
			break;
		bytes_read = read(fd, buffer, BUFF_SIZE);
		ft_dynamic_string(&all_data, buffer, bytes_read);
	}
	*line = ft_strdup(all_data);
	return (0);
}