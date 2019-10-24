/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <jmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 04:07:48 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/10/24 04:12:39 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_cdsuobx(t_printf *p)
{
	if (ft_strchr("CDSUOBX", *p->format))
		p->f |= (*p->format != 'X') ? F_LONG : F_UPCASE;
}
