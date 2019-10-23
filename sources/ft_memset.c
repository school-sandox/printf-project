/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <jmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:35:47 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/10/21 22:50:22 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int val, size_t num)
{
	int				i;
	unsigned char	*buf;

	i = 0;
	buf = (unsigned char*)b;
	while (num--)
	{
		buf[i] = (unsigned char)val;
		i++;
	}
	return (b);
}
