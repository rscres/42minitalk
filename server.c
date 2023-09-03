/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renato <renato@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:16:03 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/03 19:05:59 by renato           ###   ########.fr       */
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
	static int	len;

	if (c_pid != info->si_pid)
	{
		c_pid = info->si_pid;
	}
	if (sig == SIGUSR2)
	{
		c |= (0x01 << i);
	}
	// printf("c: %d:%#x\n", c, c);
	if (i++ == 7)
	{
		i = 0;
		len++;
		// printf("len: %d\n", len);
		if (c == BOM)
		{
			kill(c_pid, SIGUSR1);
			write(1, "\n", 2);
			ft_printf("Waiting for message...\n");
			c = 0;
			len = 0;
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
	ft_printf("Waiting for message...\n");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
