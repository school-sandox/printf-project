/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <jmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:34:29 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/10/21 22:04:43 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, unsigned char c, size_t n)
{
	int				i;
	unsigned char	*a;

	a = (unsigned char*)s;
	i = 0;
	while (n--)
	{
		if (a[i] == c)
			return ((void*)(a + i));
		i++;
	}
	return (NULL);
}
