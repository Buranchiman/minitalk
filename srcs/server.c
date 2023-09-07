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

// void receive1()
// {
// 	char	*c;

// 	c = ft_calloc(2, sizeof(char));
// 	if (g_tools[0] == 0)
// 		g_tools[0] = '0';
// 	//ft_printf("entered 1\n");
//     g_tools[1] = ((g_tools[1] << 1 ) |  1);
// 	g_tools[0]++;
// 	if (g_tools[0] == '8')
// 	{
// 		ft_putchar_fd(g_tools[1], 1);
// 		//ft_printf("its alive\nALIVEEEE\n");
// 		g_tools[0] = '0';
// 	}
// }

void	print_charlist(t_charlist **msg)
{
	t_charlist	*temp;
	char		*display;
	int i;

	i = 0;
	temp = *msg;
	//ft_printf("size of sentence is %d\n", ft_charlstsize(temp));
	display = ft_calloc(ft_charlstsize(temp) + 1, sizeof(char));
	while (temp != NULL)
	{
		display[i] = temp->c;
		//ft_printf("future of msg is %c\n", temp->next->c);
		ft_printf("char n%d of msg is %c\n", i, temp->c);
		ft_printf("char n%d of display is %c\n", i, display[i]);
		i ++;
		temp = temp->next;
	}
	//ft_putchar_fd(display[0], 1);
	ft_putstr_fd(display, 1);
	free(display);
}

// void receive0()
// {
// 	if (g_tools[0] == 0)
// 		g_tools[0] = '0';
// 	//ft_printf("entered 0\n");
// 	g_tools[1] = (g_tools[1] << 1); 
// 	g_tools[0]++;
// 	if (g_tools[0] == '8')
// 	{
// 		ft_putchar_fd(g_tools[1], 1);
// 		//ft_printf("its alive\nALIVEEEE\n");
// 		g_tools[0] = '0';
// 	}
// }

void    show_pid()
{
    pid_t pid;
    

    pid = getpid();
   // SIGUSR1 = pid;
    ft_putnbr_fd(pid, 1);
}

void	act(int sig, siginfo_t *info, void *unused)
{
	static int			i = 0;
	static char			current = 0;
	static t_charlist	*msg = NULL;
	static pid_t		pid = 0;

	(void)unused;
	if (!pid)
		pid = info->si_pid;
	i ++;
	if (sig == SIGUSR1)
	{
		current = ((current << 1) | 1);
		ft_printf("received a 1 bit\n");
	}
	else
	{
		current = current << 1;
		ft_printf("received a 0 bit\n");
	}
	if (i == 8)
	{
		ft_printf("%c\n" ,current);
		manage_charlist(&msg, current);
		ft_printf("passed manage charlist\n");
		if (current == 0)
		{
			print_charlist(&msg);
			clean_charlist(msg);
		}
		ft_printf("current after manage is %c\n" ,current);
		current = 0;
		ft_printf("current should have been reset\n");
		i = 0;
	}
}

int main()
{
    show_pid();
    struct sigaction sa;
    sa.sa_sigaction = act;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
    while (1)
		pause();
    return (0);
}