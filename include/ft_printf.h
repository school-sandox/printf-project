/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <jmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 22:30:46 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/10/24 03:45:25 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include "../libft/libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>

/*
** -------------------------- Macros Definition --------------------------------
*/

# define MAX(a, b)		b & ((a - b) >> 31) | a & (~(a - b) >> 31)
# define MIN(a, b)		a & ((a - b) >> 31) | b & (~(a - b) >> 31)
# define ABS(a)			(a < 0) ? -a : a
# define DABS(a)		(a < 0.0f) ? -a : a
# define STRERR			strerror

/*
** -------------------------- Colors Definition --------------------------------
*/

# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define PURPLE			"\033[35m"
# define CYAN			"\033[36m"
# define EOC			"\033[0m"

/*
** --------------------------- Masks Definition --------------------------------
*/

# define F_SHARP		(1 << 0)
# define F_SPACE		(1 << 1)
# define F_PLUS			(1 << 2)
# define F_MINUS		(1 << 3)
# define F_ZERO			(1 << 4)
# define F_WILDCARD		(1 << 5)
# define F_UPCASE		(1 << 6)
# define F_SHORT		(1 << 7)
# define F_SHORT2		(1 << 8)
# define F_LONG			(1 << 9)
# define F_LONG2		(1 << 10)
# define F_INTMAX		(1 << 11)
# define F_SIZE_T		(1 << 12)
# define F_MIN_LEN		(1 << 13)
# define F_APP_PRECI	(1 << 14)
# define F_POINTER		(1 << 15)
# define PF_BUF_SIZE	64

/*
** ------------------------- Structure Definition ------------------------------
*/

typedef struct			s_printf
{
	int					fd;
	int					len;
	short				f;
	short				n;
	int					min_length;
	int					accuracy;
	int					padding;
	int					printed;
	int					buffer_index;
	char				buff[PF_BUF_SIZE];
	va_list				ap;
	char				*format;
	char				is_lf;
	unsigned			c;
}						t_printf;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

int						ft_printf(const char *format, ...);
int						ft_dprintf(int fd, const char *format, ...);

/*
** -------------------------- Parsing Functions --------------------------------
*/

void					parse_opt(t_printf *p);
void					cs_not_found(t_printf *p);

/*
** -------------------------- Numbers Functions --------------------------------
*/

void					pf_putnb(t_printf *p);
void					pf_putnb_base(int base, t_printf *p);
void					itoa_printf(intmax_t d, t_printf *p, int len);
void					itoa_base_printf(uintmax_t d, int b, t_printf *p);
void					itoa_base_fill(uintmax_t tmp, int base, char *str,
						t_printf *p);

/*
** ---------------------- Strings & Chars Functions ----------------------------
*/

void					pf_putstr(t_printf *p);
void					pf_putwstr(t_printf *p);
void					pf_character(t_printf *p, unsigned c);
void					ft_printf_putstr(char *s, t_printf *p);
void					pf_putwchar(t_printf *p, unsigned int w, int wl, int n);

/*
** --------------------------- Bonus Functions ---------------------------------
*/

void					print_pointer_address(t_printf *p);
void					color(t_printf *p);
void					pf_putdouble(t_printf *p);
void					pf_putdouble_lf(t_printf *p);

/*
** --------------------------- Buffer Functions --------------------------------
*/

void					buffer(t_printf *p, void *new_elem, size_t size);
void					buffer_flush(t_printf *p);

void					padding(t_printf *p, int n);

#endif
