/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:41:49 by hlaineka          #+#    #+#             */
/*   Updated: 2019/10/28 13:53:10 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copies the first num characters of src to dest. If the end of the src is
** found before num, the rest of the dest is padded with zeros.
*/

char	*ft_strncpy(char *dest, const char *src, size_t num)
{
	unsigned int		i;

	i = 0;
	while (src[i] != '\0' && i < num)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < num)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
