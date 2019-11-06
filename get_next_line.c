#include "get_next_line.h"

static void		add_fd_list(fd_list **all_fds,char *all_data,int fd)
{
	static fd_list		*temp;
	fd_list		*index;
	fd_list		*previous;

	index = *all_fds;
	temp = (fd_list*)malloc(sizeof(fd_list));
	temp->data = all_data;
	temp->fd = fd;
	temp->next = NULL;
	previous = NULL;
	while (index)
	{
		if  (index->fd == fd && fd == 0)
		{
			temp->next = index->next;
			if (previous)
				previous->next = temp;
			else
				*all_fds = temp;
			free(index);
			return;
		}
		else if (index->fd == fd)
			return; 
		previous = index;
		index = index->next;
	}
	if (previous)
		previous->next = temp;
	else
		*all_fds = temp;
	//ft_putendl((*all_fds)->data); does it go here every time with fd 0
}

static void		remove_list(fd_list **all_fds, int fd)
{
	fd_list		*temp;
	fd_list		*previous;

	temp = *all_fds;
	if (temp->fd == fd)
	{	
		temp = *all_fds;
		*all_fds = temp->next;
		free(temp);
		return;
	}
	while (temp->fd != fd)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = temp->next;
	free(temp);
	return;
}

static int		return_list_data(fd_list **all_fds, char **return_str, int fd)
{
	fd_list		*temp;
	char		*returnable;
	int			i;

	temp = *all_fds;
	returnable = NULL;
	i = 0;
	while (temp->fd != fd)
		temp = temp->next;
	while (temp->data[i] != '\n' && temp->data[i] != '\0')
		i++;
	if (temp->data[i] == '\0')
	{	
		ft_putendl("do we get here?");
		*return_str = ft_strdup(temp->data);
		remove_list(all_fds, fd);
		return (0);
	}
	returnable = ft_strsub(temp->data, 0, i);
	*return_str = returnable;
	temp->data = &temp->data[i + 1];
	return (1);
}

static void		ft_dynamic_string(char **dest, char *src, int num)
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
	int				bytes_read;
	char			*buffer;
	char			*all_data;
	static fd_list	*all_fds;

	all_data = NULL;
	all_fds = NULL;
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
	add_fd_list(&all_fds, all_data, fd);
	return(return_list_data(&all_fds, line, fd));
}