/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:09:38 by hlaineka          #+#    #+#             */
/*   Updated: 2019/12/09 17:47:41 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 8
# define FD_LIMIT 4864

int					get_next_line(const int fd, char **line);

#endif
