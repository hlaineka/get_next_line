/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:12:38 by hlaineka          #+#    #+#             */
/*   Updated: 2019/10/29 11:16:23 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** compares str1 to str2 and return 0 if they are aqual or int representing
** the difference. Recursive function.
*/

int	ft_strcmp(const char *str1, const char *str2)
{
	if (str1[0] == '\0' || str2[0] == '\0' || str1[0] != str2[0])
		return ((unsigned char)str1[0] - (unsigned char)str2[0]);
	else
		return (ft_strcmp(&str1[1], &str2[1]));
}
