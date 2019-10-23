/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <jmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:38:32 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/10/21 22:50:39 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*a;

	i = 0;
	a = (char*)s;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (s[i] == (char)c)
			return (a + i);
		i++;
	}
	a = NULL;
	return (a);
}
