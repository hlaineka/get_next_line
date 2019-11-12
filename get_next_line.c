#include "get_next_line.h"

static void		add_fd_list(fd_list **all_fds,char *all_data,int fd)
{
	fd_list		*temp;
	fd_list		*index;
	fd_list		*previous;
	//char		*to_remove;

	//index = (fd_list*)malloc(sizeof(fd_list));
	index = *all_fds;
	temp = (fd_list*)malloc(sizeof(fd_list));
	temp->data = ft_strdup(all_data);
	temp->fd = fd;
	temp->next = NULL;
	previous = NULL;
	while (index)
	{
		if  (index->fd == fd && fd == 0)
		{
			temp->next = index->next;
			ft_putendl("inside if fd == 0 at add_fd_list");
			if (previous)
				previous->next = temp;
			else
				*all_fds = temp;
			//to_remove = index->data;
			//ft_putendl(to_remove);
			//free(to_remove);
			free(index->data);
			free(index);
			return;
		}
		else if (index->fd == fd)
		{	
			free(temp->data);
			free(temp);
			free(index);
			return; 
		}
		previous = index;
		index = index->next;
	}
	if (previous)
	{	
		previous->next = temp;
	}
	else
		*all_fds = temp;
	//ft_putendl("end of add_fd_list"); //does it go here every time with fd 0
}

static void		remove_list(fd_list **all_fds, int fd)
{
	fd_list		*temp;
	fd_list		*previous;

	ft_putendl("inside remove list");
	temp = *all_fds;
	if (temp->fd == fd)
	{	
		//ft_putendl("inside remove first");
		*all_fds = temp->next;
		free(temp->data);
		free(temp);
		return;
	}
	while (temp->fd != fd && temp != NULL)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = temp->next;
	free(temp->data);
	free(temp);
	return;
}

static int		check_fd(fd_list **all_fds, int fd)
{
	fd_list		*temp;

	//ft_putendl("inside check fd");
	//temp = (fd_list*)malloc(sizeof(fd_list*));
	temp = *all_fds;
	if (temp == NULL)
		return (-1);
	while (temp != NULL && temp->fd != fd)
		temp = temp->next;
	if (temp == NULL)
		return (-1);
	//free(temp);
	return (1);
}

static int		return_list_data(fd_list **all_fds, char **return_str, int fd)
{
	fd_list		*temp;
	char		*returnable;
	int			i;
	char		*temp_str;

	//temp = (fd_list*)malloc(sizeof(fd_list*));
	temp = *all_fds;
	returnable = NULL;
	i = 0;
	while (temp != NULL && temp->fd != fd)
		temp = temp->next;
	while (temp->data[i] != '\n' && temp->data[i] != '\0')
		i++;
	//ft_putnbr(i);
	//ft_putchar('\n');
	if (temp->data[i] == '\0' && fd != 0) //|| fd == 0)
	{	
		//ft_putendl("do we get here?");
		//if (i > 0)
		//	*return_str = ft_strsub(temp->data, 0, i);
		//else
			*return_str = ft_strdup(temp->data);
		remove_list(all_fds, fd);
		return (0);
	}
	returnable = ft_strsub(temp->data, 0, i);
	*return_str = ft_strdup(returnable);
	temp_str = ft_strdup(&temp->data[i + 1]);
	free(temp->data);
	temp->data = ft_strdup(temp_str);
	//ft_putendl("temp data:");
	//ft_putendl(temp->data);
	free(returnable);
	free(temp_str);
	return (1);
}

static void		ft_dynamic_string(char **dest, char *src, int num)
{
	char	*returnable;
	char	*temp_src;

	temp_src = ft_strnew(num + 1);
	temp_src = memcpy(temp_src, src, num);
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
	}
	free(returnable);
	free(temp_src);
	return;
}

int		get_next_line(const int fd, char **line)
{
	int				bytes_read;
	char			*buffer;
	char			*all_data;
	static fd_list	*all_fds = NULL;
	//char			*temp;
	int				returnable;
	

	all_data = NULL;
	buffer = ft_strnew(BUFF_SIZE);
	//temp = NULL;
	//ft_putendl("in the beginning");
	if (fd == -1)
		return (-1);
	if (check_fd(&all_fds, fd) == -1 || fd == 0)
	{
		//ft_putendl("just inside if");
		bytes_read = read(fd, buffer, BUFF_SIZE);
		ft_dynamic_string(&all_data, buffer, bytes_read);
		//ft_putendl("before read while");
		while (bytes_read == BUFF_SIZE)
		{
			//free(buffer);
			if (fd == 0 && buffer[BUFF_SIZE - 1] == '\n')
				break;
			bytes_read = read(fd, buffer, BUFF_SIZE);
			ft_dynamic_string(&all_data, buffer, bytes_read);
		}
		//ft_putendl("before add fd list");
		add_fd_list(&all_fds, all_data, fd);
	}
	//ft_putendl("after read while");
	returnable = return_list_data(&all_fds, line, fd);
	//ft_putendl("after return list data");
	free(all_data);
	free(buffer);
	//free(temp);
	return(returnable);
}