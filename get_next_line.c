/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:38:16 by hlaineka          #+#    #+#             */
/*   Updated: 2019/12/03 11:05:01 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_str_realloc(char *src, int start, int end)
{
	char	*new_str;

	new_str = ft_strsub(src, start, end);
	free(src);
	return (new_str);
}

static int		search_newline(char **dest, char **src)
{
	int		i;

	i = 0;
	if (!src || !*src || src[0][0] == '\0')
		return (0);
	while (src[0][i] != '\0' && src[0][i] != '\n')
		i++;
	if (src[0][i] == '\n')
	{
		if (!*dest)
			*dest = ft_strsub(*src, 0, i);
		else
			*dest = ft_str_realloc(*src, 0, i);
		*src = ft_str_realloc(*src, i + 1, ft_strlen(*src));
		return (1);
	}
	return (0);
}

static char		*ft_dynamic_string(char **dest, char *src, int num)
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
	return (*dest);
}

int				get_next_line(const int fd, char **line)
{
	static char	*fds[FD_LIMIT];
	char		buf[BUFF_SIZE];
	int			bytes;
	int			returnable;

	if (fd < 0 || fd > FD_LIMIT || !line)
		return (-1);
	*line = NULL;
	bytes = 0;
	while ((returnable = search_newline(line, &fds[fd])) == 0
		&& (bytes = read(fd, buf, BUFF_SIZE)) > 0)
		ft_dynamic_string(&fds[fd], buf, bytes);
	if (bytes < 0)
		return (-1);
	if (bytes == 0 && *line == NULL && (fds[fd] == NULL || fds[fd][0] == '\0'))
		return (0);
	if (bytes == 0 && returnable == 0 && fds[fd][0] != '\0')
	{
		*line = ft_strdup(fds[fd]);
		fds[fd] = ft_strdup("\0");
		return (1);
	}
	return (1);
}
