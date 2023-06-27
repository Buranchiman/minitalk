/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:26:34 by wvallee           #+#    #+#             */
/*   Updated: 2022/11/18 11:26:38 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_intlen(int n)
{
	int			j;
	long int	quoi;

	j = 0;
	quoi = n;
	if (n < 0)
	{
		quoi = -1 * quoi ;
		j++;
	}
	else if (n == 0)
		return (1);
	while (quoi >= 10)
	{
		quoi = quoi / 10;
		j++;
	}
	j++;
	return (j);
}

static void	ft_tab(char *tab, int div, long int feur, int i)
{	
	while (div > feur)
		div = div / 10;
	while (div >= 10)
	{
		tab[i] = feur / div + '0';
		feur = feur % div;
		div = div / 10;
		i++;
	}
	tab[i] = feur + '0';
	i++;
	tab[i] = '\0';
}

char	*ft_itoa(int n)
{
	int			div;
	char		*tab;
	int			i;
	long int	feur;

	i = 0;
	div = 1000000000;
	feur = (long int)n;
	tab = (char *)malloc((ft_intlen(n) + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	if (n < 0)
	{
		tab[0] = '-';
		i++;
		feur = -1 * feur;
	}
	while (div > feur)
		div = div / 10;
	ft_tab(tab, div, feur, i);
	return (tab);
}
