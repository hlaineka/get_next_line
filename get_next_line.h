#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include "libft/includes/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 8

typedef struct 		list_fd
{
	int				fd;
	char			*data;
	struct list_fd	*next;
}					fd_list;

int					get_next_line(const int fd, char** line);

#endif