/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:17:18 by wvallee           #+#    #+#             */
/*   Updated: 2023/06/21 12:17:22 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(char *msg, char *add)
{
	int	i;
	int	bit;
	pid_t pid;

	i = 0;
	pid = ft_atoi(add);
	while (msg[i] != '\0')
	{
		bit = 7;
		while (bit >= 0)
		{
			if (((msg[i] >> bit) & 1) == 1)
			{
				kill(pid, SIGUSR1);
				ft_printf("sent a 1 bit\n");
				usleep(1);
			}
			else
			{
				kill(pid, SIGUSR2);
				ft_printf("sent a 0 bit\n");
				usleep(1);
			}
			bit --;
		}
		i ++;
		ft_printf("retour à la ligne\n");
	}
}

void	end_msg(char *add)
{
	pid_t	pid;
	int		i;

	i = 0;
	pid = ft_atoi(add);
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(1);
		i ++;
	}
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return (0);
	send_msg(argv[2], argv[1]);
	end_msg(argv[1]);
	return (0);
}