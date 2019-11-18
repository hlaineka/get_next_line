/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:09:26 by hlaineka          #+#    #+#             */
/*   Updated: 2019/11/15 11:55:38 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		add_fdlist(t_fdlist **all_fds, char *all_data, int fd)
{
	t_fdlist	*temp;
	t_fdlist	*index;
	t_fdlist	*previous;

	index = *all_fds;
	previous = NULL;
	while (index)
	{
		if (index->fd == fd)
			return (0);
		previous = index;
		index = index->next;
	}
	if ((temp = (t_fdlist*)malloc(sizeof(t_fdlist))) == NULL)
		return (-1);
	temp->data = ft_strdup(all_data);
	temp->fd = fd;
	temp->next = NULL;
	if (previous)
		previous->next = temp;
	else
		*all_fds = temp;
	return (1);
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

static int		ret_data(t_fdlist **all_fds, char **ret_str, int fd, int check)
{
	t_fdlist	*temp;
	int			i;
	int			w;
	char		*temp_str;

	temp = *all_fds;
	i = 0;
	w = 0;
	while (temp != NULL && temp->fd != fd)
		temp = temp->next;
	if ((*all_fds == NULL || temp == NULL) && check == 1)
		return (-1);
	if (check == 1)
		return (3);
	while (temp->data[i] != '\n' && temp->data[i] != '\0')
		i++;
	while (temp->data[i + w] == '\n')
		w++;
	*ret_str = ft_strsub(temp->data, 0, i);
	if (temp->data[i + w] == '\0')
	{
		remove_list(all_fds, fd);
		return (1);
	}
	temp_str = ft_strdup(&temp->data[i + w]);
	free(temp->data);
	temp->data = ft_strdup(temp_str);
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

int				get_next_line(const int fd, char **line)
{
	int				bytes;
	char			*buf;
	char			*all_data;
	static t_fdlist	*all_fds = NULL;

	all_data = NULL;
	*line = NULL;
	bytes = BUFF_SIZE;
	if (fd == -1)
		return (-1);
	if (ret_data(&all_fds, line, fd, 1) == -1)
	{
		buf = ft_strnew(BUFF_SIZE);
		while (bytes == BUFF_SIZE && !(fd == 0 && buf[BUFF_SIZE - 1] == '\n'))
		{
			bytes = read(fd, buf, BUFF_SIZE);
			ft_dynamic_string(&all_data, buf, bytes);
		}
		free(buf);
		if (bytes == 0)
			return (0);
		if (bytes == -1 || add_fdlist(&all_fds, all_data, fd) == -1)
			return (-1);
	}
	free(all_data);
	return (ret_data(&all_fds, line, fd, 0));
}
