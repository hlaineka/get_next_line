/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:20:26 by hlaineka          #+#    #+#             */
/*   Updated: 2019/10/28 12:20:29 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Appends max num characters of src to dest
*/

char	*ft_strncat(char *dest, const char *src, size_t num)
{
	unsigned int	i;
	unsigned int	w;

	i = 0;
	w = 0;
	while (dest[i] != '\0')
		i++;
	while (src[w] != '\0' && w < num)
	{
		dest[i] = src[w];
		w++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
