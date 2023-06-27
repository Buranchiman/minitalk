/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:15:28 by wvallee           #+#    #+#             */
/*   Updated: 2023/02/02 16:40:10 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultralibft.h"

unsigned int	ft_printu(unsigned int u, char *base)
{
	unsigned int	ret;

	ret = 0;
	if (u == 0)
	{
		ret = putchar_count('0', 1);
		return (ret);
	}
	ret = ft_putnbr_base(u, base);
	return (ret);
}

int	ft_type(va_list argp, char c)
{
	int	ret;

	ret = 0;
	if (c == '%')
		ret = putchar_count('%', 1);
	else if (c == 'c')
		ret = putchar_count(va_arg(argp, int), 1);
	else if (c == 's')
		ret = ft_printstr((va_arg(argp, char *)), 1);
	else if (c == 'p')
		ret = ft_printp(va_arg(argp, unsigned long));
	else if (c == 'd' || c == 'i')
		ret = ft_printnbr((va_arg(argp, int)), "0123456789");
	else if (c == 'u')
		ret = ft_printu((va_arg(argp, unsigned int)), "0123456789");
	else if (c == 'x')
		ret = ft_printu((va_arg(argp, unsigned int)), "0123456789abcdef");
	else if (c == 'X')
		ret = ft_printu((va_arg(argp, unsigned int)), "0123456789ABCDEF");
	return (ret);
}

int	ft_nbetween(char *s, int i)
{
	int		j;
	char	*temp;

	j = 0;
	while (s[i + j] != '%' && s[i + j])
	{
		j ++;
	}
	temp = ft_strndup(&s[i], j);
	ft_printstr(temp, 1);
	free(temp);
	i = i + j;
	return (j);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	int		i;
	int		diff;
	va_list	argp;

	va_start(argp, format);
	ret = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ret += ft_type(argp, format[i]);
			i++;
		}
		else
		{	
			diff = ft_nbetween((char *)format, i);
			ret += diff;
			i += diff;
		}
	}
	va_end(argp);
	return (ret);
}
