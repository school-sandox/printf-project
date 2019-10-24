/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <jmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:38:57 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/10/24 04:04:10 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			color(t_printf *p)
{
	int len;

	p->printed = 5;
	if (!ft_strncmp(p->format, "{red}", (len = 5)))
		buffer(p, RED, p->printed);
	else if (!ft_strncmp(p->format, "{green}", (len = 7)))
		buffer(p, GREEN, p->printed);
	else if (!ft_strncmp(p->format, "{yellow}", (len = 8)))
		buffer(p, YELLOW, p->printed);
	else if (!ft_strncmp(p->format, "{blue}", (len = 6)))
		buffer(p, BLUE, p->printed);
	else if (!ft_strncmp(p->format, "{purple}", (len = 8)))
		buffer(p, PURPLE, p->printed);
	else if (!ft_strncmp(p->format, "{cyan}", (len = 6)))
		buffer(p, CYAN, p->printed);
	else if (!ft_strncmp(p->format, "{eoc}", (len = 5)))
		buffer(p, EOC, --p->printed);
	else if (!(len = 0))
		p->printed = 0;
	p->format += len - 1;
	p->len += p->printed;
}

static void		ldtoa_fill(double n, t_printf *p, long value)
{
	int		len;
	int		accuracy;
	char	s[48];

	len = p->printed - 1 - p->accuracy;
	accuracy = p->printed - 1 - len;
	while (accuracy--)
	{
		s[len + accuracy + 1] = value % 10 + '0';
		value /= 10;
	}
	(p->accuracy > 0) ? s[len] = '.' : 0;
	value = (long)(ABS(n));
	while (++accuracy < len)
	{
		s[len - accuracy - 1] = value % 10 + '0';
		value /= 10;
	}
	(p->f & F_APP_PRECI && p->f & F_ZERO) ? s[0] = ' ' : 0;
	(p->f & F_SPACE) ? s[0] = ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	(p->f & F_PLUS && n >= 0) ? s[0] = '+' : 0;
	buffer(p, s, len + 1 + 6);
}

void			pf_putdouble(t_printf *p)
{
	double		n;
	long		tmp;
	int			len;
	double		decimal;
	long		value;

	n = (long double)va_arg(p->ap, double);
	(p->f & F_ZERO) ? p->accuracy = p->min_length : 0;
	if (!(p->f & F_APP_PRECI))
		p->accuracy = 6;
	len = (p->accuracy > 0) ? 1 : 0;
	tmp = (long)(ABS(n));
	while (tmp && ++len)
		tmp /= 10;
	(p->f & F_ZERO) ? p->accuracy = p->min_length : 0;
	p->printed = p->accuracy + len + ((n < 0) ? 1 : 0);
	decimal = ((n < 0.0f) ? -n : n);
	decimal = (decimal - (long)(((n < 0.0f) ? -n : n))) *
	ft_pow(10, p->accuracy + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
	value = (int)decimal;
	ldtoa_fill(n, p, value);
}

void			pf_putdouble_lf(t_printf *p)
{
	long double		n;
	long			tmp;
	int				len;
	long double		decimal;
	long			value;

	n = va_arg(p->ap, long double);
	(p->f & F_ZERO) ? p->accuracy = p->min_length : 0;
	if (!(p->f & F_APP_PRECI))
		p->accuracy = 6;
	len = (p->accuracy > 0) ? 1 : 0;
	tmp = (long)(ABS(n));
	while (tmp && ++len)
		tmp /= 10;
	(p->f & F_ZERO) ? p->accuracy = p->min_length : 0;
	p->printed = p->accuracy + len + ((n < 0) ? 1 : 0);
	decimal = ((n < 0.0f) ? -n : n);
	decimal = (decimal - (long)(((n < 0.0f) ? -n : n))) *
	ft_pow(10, p->accuracy + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
	value = (int)decimal;
	ldtoa_fill(n, p, value);
}

void			set_lf(t_printf *p)
{
	p->is_lf = 'y';
	p->f |= F_LONG2;
}
