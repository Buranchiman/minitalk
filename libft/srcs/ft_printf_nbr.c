/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:25:52 by wvallee           #+#    #+#             */
/*   Updated: 2023/01/18 11:48:10 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	size_base(long long nbr, char *base)
{
	unsigned int	size;
	unsigned int	len;

	size = 0;
	if (nbr < 0)
		size++;
	len = ft_strllen(base);
	while (nbr)
	{
		nbr = nbr / len;
		size++ ;
	}
	return (size);
}

char	*ft_tabnbr(long long nbr, unsigned int size, char *base)
{
	char	*tab;

	tab = (char *)malloc(size + 1 * sizeof(char));
	if (tab == NULL)
		return (0);
	ft_bzero(tab, size + 1);
	if (nbr < 0)
	{
		tab[0] = '-';
		nbr = -1 * nbr;
	}
	size --;
	while (nbr != 0)
	{
		tab[size] = nbr % ft_strllen(base);
		tab[size] = base[(int)tab[size]];
		nbr = nbr / ft_strllen(base);
		size--;
	}
	return (tab);
}

unsigned int	ft_putnbr_base(long long nbr, char *base)
{
	char			*tab;
	unsigned int	size;
	unsigned int	count;

	size = size_base(nbr, base);
	tab = ft_tabnbr(nbr, size, base);
	count = ft_printstr(tab, 1);
	free(tab);
	return (count);
}

unsigned int	ft_printnbr(int nbr, char *base)
{
	unsigned int	ret;

	if (nbr == 0)
	{
		putchar_count('0', 1);
		return (1);
	}
	ret = ft_putnbr_base(nbr, base);
	return (ret);
}
