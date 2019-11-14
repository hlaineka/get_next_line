/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:09:26 by hlaineka          #+#    #+#             */
/*   Updated: 2019/11/13 11:16:29 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		add_fdlist(t_fdlist **all_fds, char *all_data, int fd)
{
	t_fdlist	*temp;
	t_fdlist	*index;
	t_fdlist	*previous;

	index = *all_fds;
	temp = (t_fdlist*)malloc(sizeof(t_fdlist));
	if (temp == NULL)
		return (-1);
	temp->data = ft_strdup(all_data);
	temp->fd = fd;
	temp->next = NULL;
	previous = NULL;
	while (index)
	{
		if (index->fd == fd)
		{
			free(temp->data);
			free(temp);
			free(index);
			return (0);
		}
		previous = index;
		index = index->next;
	}
	if (previous)
		previous->next = temp;
	else
		*all_fds = temp;
	return(1);
}

static void		remove_list(t_fdlist **all_fds, int fd)
{
	t_fdlist	*temp;
	t_fdlist	*previous;

	temp = *all_fds;
	if (temp->fd == fd)
	{
		*all_fds = temp->next;
		free(temp->data);
		free(temp);
		return ;
	}
	while (temp->fd != fd && temp != NULL)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = temp->next;
	free(temp->data);
	free(temp);
	return ;
}

static int		return_list_data(t_fdlist **all_fds, char **return_str, int fd, int check)
{
	t_fdlist	*temp;
	char		*returnable;
	int			i;
	int			w;
	char		*temp_str;

	temp = *all_fds;
	returnable = "";
	i = 0;
	w = 0;
	if (temp == NULL && check == 1)
		return (-1);
	while (temp != NULL && temp->fd != fd)
		temp = temp->next;
	if (temp == NULL && check == 1)
		return (-1);
	if (check == 1)
		return (3);
	while (temp->data[i] != '\n' && temp->data[i] != '\0')
		i++;
	while (temp->data[i + w] == '\n')
		w++;
	*return_str = ft_strsub(temp->data, 0, i);	 
	if (temp->data[i + w] == '\0')
	{
		remove_list(all_fds, fd);
		return (1);
	}
	temp_str = ft_strdup(&temp->data[i + w]);
	free(temp->data);
	temp->data = ft_strdup(temp_str);
	free(returnable);
	free(temp_str);
	return (1);
}

static void		ft_dynamic_string(char **dest, char *src, int num)
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
	}
	free(returnable);
	free(temp_src);
	return ;
}

int				get_next_line(const int fd, char **line)
{
	int				bytes_read;
	char			*buffer;
	char			*all_data;
	static t_fdlist	*all_fds = NULL;
	int				returnable;

	all_data = NULL;
	buffer = ft_strnew(BUFF_SIZE);
	*line = ft_strnew(BUFF_SIZE);
	returnable = 0;
	bytes_read = BUFF_SIZE;
	if (fd == -1)
		return (-1);
	if (return_list_data(&all_fds, line, fd, 1) == -1)
	{
		while (bytes_read == BUFF_SIZE)
		{
			bytes_read = read(fd, buffer, BUFF_SIZE);
			ft_dynamic_string(&all_data, buffer, bytes_read);
			if (bytes_read == 0)
			{	
				free (buffer);
				return (0);
			}
			if (bytes_read == -1)
			{
				free (buffer);
				return (-1);
			}
			else if (fd == 0 && buffer[BUFF_SIZE - 1] == '\n')
				break ;	
		}
		if (add_fdlist(&all_fds, all_data, fd) == -1)
			return (-1);
	}
	returnable = return_list_data(&all_fds, line, fd, 0);
	free(all_data);
	free(buffer);
	return (returnable);
}
