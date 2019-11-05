/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:45:19 by hlaineka          #+#    #+#             */
/*   Updated: 2019/10/29 12:09:31 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
** compares two strings and returns 0 if they are not equal and 1 if they are
*/

int	ft_strequ(char const *s1, char const *s2)
{
	if (ft_strcmp(s1, s2) != 0)
		return (0);
	return (1);
}
