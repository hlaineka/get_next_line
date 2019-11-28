#include "get_next_line.h"

static int		search_newline(char **dest, char **src)
{
	int		i;
	char	*temp_str;
	
	i = 0;
	if (!src || !*src || src[0][0] == '\0')
		return (0);
	while (src[0][i] != '\0' && src[0][i] != '\n')
		i++;
	if (src[0][i] == '\0')
		return (0);
	*dest = ft_strsub(*src, 0, i);
	if (src[0][i] == '\n')
		temp_str = ft_strdup(&src[0][i + 1]);
	else
		temp_str = ft_strdup(&src[0][i]);
	free(*src);
	*src = ft_strdup(temp_str);
	free(temp_str);
	return (1);
}

static int		ft_dynamic_string(char **dest, char *src, int num)
{
	char	*returnable;
	char	*temp_src;

	temp_src = ft_strnew(num + 1);
	temp_src = ft_memcpy(temp_src, src, num);
	temp_src[num] = '\0';
	returnable = NULL;
	if (!*dest)
		*dest = ft_strdup(temp_src);
	else
	{
		returnable = ft_strjoin(*dest, temp_src);
		free(temp_src);
		temp_src = *dest;
		*dest = ft_strdup(returnable);
		free(returnable);
	}
	free(temp_src);
	return (1);
}

int get_next_line(const int fd, char **line)
{
	static char	*fds[FD_LIMIT];
	char		*buf;
	char		*all_data;
	int			bytes;
	int			returnable;

	*line = NULL;
	bytes = BUFF_SIZE;
	if (fd == -1)
		return (-1);
	buf = ft_strnew(BUFF_SIZE);
	all_data = NULL;
	if (fds[fd] != NULL)
		all_data = ft_strdup(fds[fd]);
	returnable = search_newline(line, &all_data);
	while (bytes > 0 && returnable == 0)
	{
		bytes = read(fd, buf, BUFF_SIZE);
		if (bytes == -1)
			return (-1);
		ft_dynamic_string(&all_data, buf, bytes);
		returnable = search_newline(line, &all_data);
	}
	fds[fd] = ft_strdup(all_data);
	free(buf);
	free(all_data);
	return (returnable);
}