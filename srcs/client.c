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
			//	ft_printf("sent 1\n", bit);
				usleep(1);
			}
			else
			{
				kill(pid, SIGUSR2);
			//	ft_printf("sent 0\n", bit);
				usleep(1);
			}
			bit --;
		}
		i ++;
	}
}

int main(int argc, char **argv)
{
    if (argc < 3)
    	return (0);
send_msg(argv[2], argv[1]);
}