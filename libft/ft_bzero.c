/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:14:20 by hlaineka          #+#    #+#             */
/*   Updated: 2019/10/22 12:42:57 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes as a parameter a pointer to an array. Sets n number of bytes from
** the beginning of the array as 0
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
