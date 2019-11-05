/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:40:43 by hlaineka          #+#    #+#             */
/*   Updated: 2019/10/22 12:49:31 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copies num characters from dest to src
*/

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char		*temp_dest;
	unsigned const char	*temp_src;

	temp_dest = dest;
	temp_src = src;
	if (dest && src)
	{
		while (num > 0)
		{
			temp_dest[num - 1] = temp_src[num - 1];
			num--;
		}
	}
	return (dest);
}
