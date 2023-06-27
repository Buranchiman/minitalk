/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:35:18 by wvallee           #+#    #+#             */
/*   Updated: 2023/01/05 17:09:00 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	div;
	long int	recep;

	recep = (long int)n;
	div = 1000000000;
	if (recep < 0)
	{
		recep = -1 * recep;
		ft_putchar_fd('-', fd);
	}
	while (div > recep)
		div = div / 10;
	while (div >= 10)
	{
		ft_putchar_fd(recep / div + '0', fd);
		recep = recep % div;
		div = div / 10;
	}
	ft_putchar_fd(recep + '0', fd);
}
