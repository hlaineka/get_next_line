#include "get_next_line.h"

static void		remove_from_list(fd_list *to_remove, fd_list **first)
{
	fd_list	*temp;

	temp = *first;
	if ((*first)->fd == to_remove->fd)
	{
		free (first);
		first = NULL;
		return;
	}
	while (temp->next->fd != to_remove->fd)
	{
		temp = temp->next;
	}
	temp->next = to_remove->next;
	free (to_remove);
}

static void		add_to_list(fd_list **first, char *all_read, int fd)
{
	fd_list	*temp;
	fd_list *temp_first;

	temp = (fd_list*)malloc(sizeof(fd_list));
	temp_first = (fd_list*)malloc(sizeof(fd_list));
	temp->fd = fd;
	temp->data = all_read;
	temp->next = NULL;
	ft_putendl(temp->data);
	ft_putnbr(temp->fd);
	if (*first == NULL)
	{
		ft_putendl("we got to the first one");
		first = &temp;
		ft_putendl((*first)->data);
		ft_putnbr((*first)->fd);
		ft_putendl("just before return");
		return;
	}
	else
	{
		ft_putendl("we got to the second one");
		temp_first =  *first;
		while (temp_first->next != NULL)
		{
			if (temp_first->fd == fd || temp_first->next->fd == fd)
				return;
			temp_first = temp_first->next;
		}
		temp_first->next = temp;
	}
}

static int		fd_line(fd_list **first, int fd, char **line)
{
	fd_list	*temp;
	int		i;

	temp = *first;
	ft_putendl("just inside ft_line");
	ft_putnbr((*first)->fd);
	while (temp->fd != fd)
	{
		ft_putendl("inside while");
		temp = temp->next;
	}
	i = 0;
	ft_putendl("before ending while");
	while (temp->data[i] != '\n' && temp->data[i] != '\0')
		i++;
	ft_putendl("before strsub");
	*line = ft_strsub(temp->data, 0, i);
	*line[i] = '\0';
	ft_putendl(*line);
	if (temp->data[i] == '\0')
	{
		remove_from_list(temp, first);
		return (0);
	}
	temp->data = &temp->data[i];
	return (1);
}

static void		make_string(char **all_read, char *buffer, int bytes_read)
{
	int		i;
	char	*temp;
	char	*old;
	int		return_int;

	return_int = 1;
	i = 0;
	temp = ft_strnew(bytes_read + 1);
	ft_memcpy(temp, buffer, bytes_read);
	temp[bytes_read + 1] = '\0';
	if (*all_read)
	{
		old = *all_read;
		*all_read = ft_strjoin(*all_read, temp);
		free (old);
	}
	else
		*all_read = ft_strdup(temp);
}

int     		get_next_line(const int fd, char** line)
{
    int 			bytes_read;
	char			*buffer;
	char			*all_read;
	static fd_list	*all_fds;
	int				returnable;

	buffer = ft_strnew(BUFF_SIZE + 1);
	bytes_read = BUFF_SIZE;
	all_read = NULL;
	all_fds = NULL;
	//kay lapi lista ettei tartte joka kerta teha stringia?
	while (bytes_read == BUFF_SIZE)
	{
		bytes_read = read (fd, buffer, BUFF_SIZE);
		make_string(&all_read, buffer, bytes_read);
	}
	ft_putendl("we got out of the while");
	add_to_list(&all_fds, all_read, fd);
	ft_putendl("we got out add to list");
	ft_putnbr(all_fds->fd);
	ft_putendl(all_fds->data);
	returnable = fd_line(&all_fds, fd, &buffer);
	ft_putendl("we got out of fd line");
	ft_putendl(buffer);
	*line = buffer;
	ft_putendl(*line);
	return (returnable);
}