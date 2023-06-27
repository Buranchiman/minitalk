/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:02:17 by wvallee           #+#    #+#             */
/*   Updated: 2023/01/18 11:57:23 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

unsigned int	size_p(unsigned long address)
{
	unsigned int	size;

	size = 0;
	while (address)
	{
		address = address / 16;
		size++;
	}
	return (size);
}

unsigned int	putp(unsigned long address)
{
	unsigned int	size;
	unsigned int	ret;
	char			*tab;
	char			*base;

	base = "0123456789abcdef";
	ret = 0;
	size = size_p(address);
	tab = (char *)malloc(size + 1 * sizeof(char));
	if (tab == NULL)
		return (0);
	ft_bzero(tab, size + 1);
	size--;
	while (address)
	{
		tab[size] = address % 16;
		tab[size] = base[(int)tab[size]];
		address = address / 16;
		size --;
	}
	ret = ft_printstr(tab, 1);
	free(tab);
	return (ret);
}

unsigned int	ft_printp(unsigned long address)
{
	unsigned int	ret;

	if (address == 0)
	{
		ret = ft_printstr("(nil)", 1);
		return (ret);
	}
	ret = ft_printstr("0x", 1);
	ret += putp(address);
	return (ret);
}
