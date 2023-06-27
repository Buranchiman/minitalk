/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:45:18 by wvallee           #+#    #+#             */
/*   Updated: 2023/06/15 13:45:28 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char		g_tools[3] = {0};

void receive1()
{
	if (g_tools[0] == 0)
		g_tools[0] = '0';
	//ft_printf("entered 1\n");
    g_tools[1] = ((g_tools[1] << 1 ) |  1);
	g_tools[0]++;
	if (g_tools[0] == '8')
	{
		ft_putchar_fd(g_tools[1], 1);
		//ft_printf("its alive\nALIVEEEE\n");
		g_tools[0] = '0';
	}
}

void receive0()
{
	if (g_tools[0] == 0)
		g_tools[0] = '0';
	//ft_printf("entered 0\n");
	g_tools[1] = (g_tools[1] << 1); 
	g_tools[0]++;
	if (g_tools[0] == '8')
	{
		ft_putchar_fd(g_tools[1], 1);
		//ft_printf("its alive\nALIVEEEE\n");
		g_tools[0] = '0';
	}
}
void    show_pid()
{
    pid_t pid;
    

    pid = getpid();
   // SIGUSR1 = pid;
    ft_putnbr_fd(pid, 1);
}

int main()
{
    show_pid();
    struct sigaction sa;
    sa.sa_handler = receive1;
	struct sigaction sb;
    sb.sa_handler = receive0;

	//printf("current bit is %c\n", g_tools[0]);
    while (1)
	{
        sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sb, NULL);
	}
    return (0);
}