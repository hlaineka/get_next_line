#include "get_next_line.h"

static int		search_newline(char **dest, char **src)
{
	int		i;
	char	*temp_str;
	
	i = 0;
	ft_putendl("sn1");
	if (!src || !*src)
		return (0);
	ft_putendl("sn2");
	while (src[0][i] != '\0' && src[0][i] != '\n')
		i++;
	ft_putendl("sn3");
	if (src[0][0] == '\0')
		return (0);
	ft_putendl("sn4");
	*dest = ft_strsub(*src, 0, i);
	if (src[0][i] == '\0')
	{
		free(*src);
		*src = ft_strdup("\0");
	}
	else
	{
		temp_str = ft_strdup(&src[0][i + 1]);
		ft_putendl("sn5");
		free(*src);
		*src = ft_strdup(temp_str);
		free(temp_str);
	}
	ft_putendl(*src);
	ft_putendl(*dest);
	return (1);
}

static void		ft_lstaddcont(t_list **alst, int fd, char *src)
{
	t_list	*temp;
	int		number_of_fds;

	temp = *alst;
	number_of_fds = 0;
	while (temp && number_of_fds < fd)
	{
		number_of_fds++;
		temp = temp->next;
	}
	free(temp->content);
	temp->content = ft_strdup(src);
}

static int		check_fd(int fd, char **dest, t_list **all_fds)
{
	t_list	*temp;
	t_list	*previous;
	int		number_of_fds;

	temp = *all_fds;
	number_of_fds = 0;
	previous = NULL;
	while (temp && number_of_fds < fd)
	{
		number_of_fds++;
		previous = temp;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		while (number_of_fds <= fd)
		{
			temp = ft_lstnew(NULL, 0);
			if(previous)
				previous->next = temp;
			else
				*all_fds = temp;
			number_of_fds++;
		}
	}
	else
		*dest = temp->content;
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

int		get_next_line(const int fd, char** line)
{
	int				bytes;
	char			*buf;
	char			*all_data;
	char			*returnable_data;
	static t_list	*all_fds = NULL;
	int				newline_found;


	all_data = ft_strnew(BUFF_SIZE);
	*line = NULL;
	returnable_data = NULL;
	bytes = BUFF_SIZE;
	newline_found = 0;
	if (fd == -1)
		return (-1);
	check_fd(fd, &all_data, &all_fds);
	buf = ft_strnew(BUFF_SIZE);
	while (bytes > 0 && newline_found == 0)
	{
		ft_putendl("hello5");
		bytes = read(fd, buf, BUFF_SIZE);
		ft_dynamic_string(&all_data, buf, bytes);
		newline_found = search_newline(&returnable_data, &all_data);
		//if (fd == 0 && buf[BUFF_SIZE - 1] == '\n')
		//	break;
	}
	ft_putendl("hello4");
	if (bytes == -1)
		return (-1);
	if (bytes == 0 && newline_found == 0)
		return (0);
	//free(buf);
	ft_lstaddcont(&all_fds, fd, all_data);
	ft_putendl("hello");
	ft_putendl(returnable_data);
	ft_putendl("hello2");
	*line = ft_strdup(returnable_data);
	ft_putendl("hello3");
	free (returnable_data);
	return (1);
}