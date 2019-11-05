/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:22:06 by hlaineka          #+#    #+#             */
/*   Updated: 2019/10/28 12:22:08 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** compares up to num characters of str2 to str1. Returns 0 if strings are
** aqual or an integer representing the difference.
*/

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	if (num == 0)
		return (0);
	if (str1[0] == '\0' || str2[0] == '\0' || str1[0] != str2[0]
			|| num == 1)
		return ((unsigned char)str1[0] - (unsigned char)str2[0]);
	else
		return (ft_strncmp(&str1[1], &str2[1], num - 1));
}
