/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <jmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:22:40 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/10/21 22:50:03 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	propusk(char const *str, int *n)
{
	int	i;
	int	l;

	l = 0;
	i = 0;
	while ((((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32)
	|| (str[i] == '-') || (str[i] == '+')) && (*n == 1) &&
	(l == 0) && (str[i] != '\0'))
	{
		if (str[i] == '-')
			*n = *n * -1;
		if (str[i] == '+')
			l = 1;
		i++;
	}
	return (i);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		j;
	int		n;
	size_t	r;

	j = 0;
	n = 1;
	r = 0;
	i = propusk(str, &n);
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		if (r >= 922337203685477580)
		{
			if ((((str[i] - '0') >= 7) || (j == 19)) && (n == 1))
				return (-1);
			if ((((str[i] - '0') >= 8) || (j == 19)) && (n == -1))
				return (0);
		}
		r = (r * 10) + (str[i] - '0');
		i++;
		j++;
	}
	return ((int)r * n);
}
