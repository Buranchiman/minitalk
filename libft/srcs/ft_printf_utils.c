/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:46:42 by wvallee           #+#    #+#             */
/*   Updated: 2023/01/10 16:38:37 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	putchar_count(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

size_t	ft_strllen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

unsigned int	ft_printstr(char *s, int fd)
{
	unsigned int	len;

	len = 0;
	if (s == NULL)
	{
		len = 6;
		write(fd, "(null)", 6);
	}
	else
	{
		len = ft_strllen(s);
		write(fd, s, len);
	}
	return (len);
}
