/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:33:07 by hlaineka          #+#    #+#             */
/*   Updated: 2019/10/28 11:33:09 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns a pointer to the first occurance of c in src
*/

char	*ft_strchr(const char *src, int c)
{
	int		i;
	char	temp_c;

	i = 0;
	temp_c = c;
	while (src[i] != '\0')
	{
		if (src[i] == c)
			return (char*)&src[i];
		i++;
	}
	if (src[i] == c)
		return (char*)&src[i];
	return (NULL);
}
