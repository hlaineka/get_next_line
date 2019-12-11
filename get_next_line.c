
#include "get_next_line.h"
#include "libft.h"

static	int		input_line(char *str[], char **line, const int fd)
{
	size_t		len;
	char		*tmp;

	len = 0;
	if (ft_strchr(str[fd], '\n'))
	{
		while ((str[fd][len] != '\n' && str[fd][len] != '\0'))
			len++;
		if (!(*line = ft_strsub(str[fd], 0, len)))
			return (-1);
		if (str[fd][len + 1] != '\0')
		{
			tmp = ft_strdup(&str[fd][len + 1]);
			ft_strdel(&str[fd]);
			str[fd] = tmp;
		}
		else
			ft_strdel(&str[fd]);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*str[2048];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	while (line != NULL && ((ret = read(fd, buff, BUFF_SIZE)) > 0))
	{
		if (str[fd] == NULL && !(str[fd] = ft_strnew(0)))
			return (-1);
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(str[fd], buff)))
			return (-1);
		ft_strdel(&str[fd]);
		str[fd] = tmp;
		if (ft_strchr(tmp, '\n'))
			return (input_line(str, line, fd));
	}
	if (ret < 0 || fd < 0 || line == NULL)
		return (-1);
	else if ((ret == 0) && (str[fd] != NULL))
		return (input_line(str, line, fd));
	else
		return ((int)(*line = NULL));
}
