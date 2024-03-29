/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacgyve <jmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 22:28:00 by jmacgyve          #+#    #+#             */
/*   Updated: 2019/10/21 22:51:20 by jmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define LBITS 0x101010101010101L
# define HBITS 0x8080808080808080L
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);

void				*ft_memchr(const void *s, unsigned char c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);

double				ft_pow(double n, int pow);

char				*ft_strchr(const char *s, int c);
int					ft_strchri(char *s, int c, int i);
int					ft_strchri_lu(char *s, int c, int i);

size_t				ft_strlen(const char *str);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

size_t				ft_wcharlen(unsigned c);
size_t				ft_wstrlen(unsigned *s);

#endif
