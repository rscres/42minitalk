/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:16:03 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/05 20:48:17 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

int	save_to_str(unsigned int c, int len, int c_pid)
{
	static char	*str;
	char		*temp;
	int			i;

	ft_printf("%c\n", c);
	if (c == '\0')
	{
		if (kill(c_pid, SIGUSR1) == -1)
		{
			if (str)
				free(str);
			str = NULL;
			exit(1);
		}
		ft_printf("\n->%s", str);
		// ft_printf("free1\n");
		if (str)
			free(str);
		// str = NULL;
		return (1);
	}
	if (!str)
	{
		str = malloc(sizeof(char) * 2);
		str[0] = c;
		str[1] = '\0';
	}
	else
	{
		temp = strdup(str);
		if (!temp)
		{
			if (str)
				free(str);
			exit(1);
		}
		// ft_printf("temp:%s\n", temp);
		if (str)
			free(str);
		str = malloc(sizeof(char) * (len + 1));
		bzero(str, len + 1);
		i = -1;
		while (temp[++i])
			str[i] = temp[i];
		str[len] = c;
		str[len + 1] = '\0';
		// ft_printf("str:%s\n", str);
		// ft_printf("free2\n");
		if (temp)
			free(temp);
	}
	return (0);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned int	c;
	static int			i;
	static int			c_pid;
	static int			len;

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
		if (save_to_str(c, len++, c_pid))
			len = 0;
		c = 0;
		i = 0;
	}
	kill(c_pid, SIGUSR2);
	if (context)
		context = NULL;
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	usleep(0.5 * 10e5);
	ft_printf("Waiting for message...");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
