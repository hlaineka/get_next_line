/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:35:03 by hlaineka          #+#    #+#             */
/*   Updated: 2019/10/31 11:42:33 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** turns intiger value to char*
*/

char		*ft_itoa(int n)
{
	static char	*str;
	int			w;

	if (NULL != (str = (char*)malloc(sizeof(char) * (ft_define_length(n) + 1))))
	{
		w = ft_define_length(n) - 1;
		str[w + 1] = ('\0');
		if (n == T_INT_MIN)
		{
			free (str);
			return (ft_strdup("-2147483648"));
		}
		if (n < 0)
		{
			str[0] = ('-');
			n = n * (-1);
		}
		while (n >= 10)
		{
			str[w--] = ((n % 10) + '0');
			n = n / 10;
		}
		str[w] = n + '0';
		return (str);
	}
	return (NULL);
}
