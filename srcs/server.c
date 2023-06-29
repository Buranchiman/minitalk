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

void receive1()
{
	char	*c;

	c = ft_calloc(2, sizeof(char));
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

void	act(int sig, siginfo_t *info, NULL)
{

}

int main()
{
    show_pid();
    struct sigaction sa;
    sa.sa_sigaction = act;
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
    while (1)
		pause();
    return (0);
}