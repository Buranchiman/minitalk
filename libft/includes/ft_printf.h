/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:53:52 by wvallee           #+#    #+#             */
/*   Updated: 2023/01/18 12:39:47 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ultralibft.h"

unsigned int	putchar_count(char c, int fd);
size_t			ft_strllen(char *str);
unsigned int	ft_printstr(char *s, int fd);
int				ft_check(char *str);
unsigned int	size_base(long long nbr, char *base);
char			*ft_tabnbr(long long nbr, unsigned int size, char *base);
unsigned int	ft_putnbr_base(long long nbr, char *base);
unsigned int	ft_printnbr(int nbr, char *base);
unsigned int	size_p(unsigned long address);
unsigned int	putp(unsigned long address);
unsigned int	ft_printp(unsigned long address);
unsigned int	ft_printu(unsigned int u, char *base);
int				ft_type(va_list argp, char c);
int				ft_nbetween(char *s, int i);
int				ft_printf(const char *format, ...);

#endif
