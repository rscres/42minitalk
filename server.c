/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:16:03 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/03 20:01:55 by renato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdio.h>

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	c;
	static int	i;
	static int	c_pid;

	if (c_pid != info->si_pid)
	{
		c_pid = info->si_pid;
	}
	if (sig == SIGUSR2)
	{
		c |= (0x01 << i);
	}
	if (i++ == 7)
	{
		i = 0;
		if (c == BOM)
		{
			kill(c_pid, SIGUSR1);
			ft_printf("\n->");
			c = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
	kill(c_pid, SIGUSR2);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	usleep(0.5 * 10e5);
	ft_printf("Waiting for message...\n->");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
