/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:16:03 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/02 22:25:16 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	c;
	static int	i;
	static int	c_pid;

	if (c_pid != info->si_pid)
	{
		c_pid = info->si_pid;
		// ft_printf("Sender PID: %d\n", c_pid);
	}
	if (sig == SIGUSR2)
	{
		c |= (0x01 << i);
	}
	if (++i == 8)
	{
		write(1, &c, 1);
		i = 0;
		if (c == '\0')
		{
			kill(c_pid, SIGUSR1);
			write(1, "\n", 2);
			c = 0;
			return ;
		}
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
