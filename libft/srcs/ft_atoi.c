/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:59:45 by wvallee           #+#    #+#             */
/*   Updated: 2022/11/29 15:02:06 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *nptr)
{
	int	signe;
	int	i;
	int	puissance;
	int	total;

	signe = 1;
	i = 0;
	total = 0;
	puissance = 1;
	while (('\t' <= nptr[i] && nptr[i] <= '\r' ) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] != '\0' && ('0' <= nptr[i] && nptr[i] <= '9'))
	{
		total = (total * puissance) + (nptr[i] - '0');
		puissance = 10;
		i++;
	}
	return (total * signe);
}
