/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:53:59 by jlimones          #+#    #+#             */
/*   Updated: 2023/06/08 12:05:01 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, int len)
{
	int			i;
	const char	*s;
	char		*d;

	s = (char *)src;
	d = (char *)dst;
	if (d > s)
	{
		i = len;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	else if (d < s)
	{
		i = 0;
		while (i < len)
		{
				d[i] = s[i];
				i++;
		}
	}
	return (dst);
}
