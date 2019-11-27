#include "get_next_line.h"

static void		ft_add_string(char ***array, const char *str, int size)
{
    int 	i;
	char	**temp;
    
	i = 0;
	while (*(array + i) != NULL)
		i++;
	ft_putendl("wtf3");
	if (i == 0)
	{	
		*array = (char**)malloc(sizeof(char*));
		array[0][0] = (char*)malloc(sizeof(char*));
		array[0][0] = NULL;
	}
	while (i <= size)
	{
		temp = (char**)malloc(sizeof(char*) * (i + 1));
		ft_memcpy(temp, *array, sizeof(char*) * i);
		free (*array);
    	ft_memcpy(*array, temp, sizeof(char*) * (i));
		//free(temp);
		array[0][i] = ft_strnew(1);
		array[0][i + 1] = NULL;
		i++;
		ft_putendl("wtf");
	}
	free(array[0][size]);
	ft_putendl("wtf2");
	array[0][size] = ft_strdup(str);
	ft_putstr("array[size] in ft_add_string: ");
	ft_putendl(array[0][size]);
}

static int		search_newline(char **dest, char **src)
{
	int		i;
	char	*temp_str;
	
	i = 0;
	if (!src || !*src)
		return (0);
	while (src[0][i] != '\0' && src[0][i] != '\n')
		i++;
	if (src[0][0] == '\0' || src[0][i] == '\0')
		return (0);
	*dest = ft_strsub(*src, 0, i);
	temp_str = ft_strdup(&src[0][i + 1]);
	free(*src);
	*src = ft_strdup(temp_str);
	free(temp_str);
	ft_putstr("src inside search_newline: ");
	ft_putendl(*src);
	return (1);
}

char	*get_data(char **array, int index)
{
	int		i;
	char	*returnable;

	i = 0;
	returnable = NULL;
	while (array[i] != NULL)
		i++;
	if (i > index)
		returnable = ft_strdup(array[index]);
	return (returnable);
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
	static char	*fds[] = { NULL };
	char		*buf;
	char		*all_data;
	int			bytes;
	int			returnable;
	char		*returnable_data;

	*line = NULL;
	bytes = BUFF_SIZE;
	returnable_data = NULL;
	if (fd == -1)
		return (-1);
	buf = ft_strnew(BUFF_SIZE);
	all_data = get_data(fds, fd);
	ft_putstr("fd: ");
	ft_putnbr(fd);
	ft_putstr("all_data after get_data: ");
	if (all_data != NULL)
		ft_putendl(all_data);
	returnable = search_newline(&returnable_data, &all_data);
	while (bytes == BUFF_SIZE && returnable == 0)
	{
		ft_putendl("inside while");
		bytes = read(fd, buf, BUFF_SIZE);
			if (bytes == -1)
			return (-1);
		ft_dynamic_string(&all_data, buf, bytes);
		returnable = search_newline(&returnable_data, &all_data);
	}
	ft_add_string((char***)&fds, all_data, fd);
	ft_putstr("string in fds array");
	ft_putendl(fds[fd]);
	free(buf);
	free(all_data);
	*line = returnable_data;
	return (returnable);
}