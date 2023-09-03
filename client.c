/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:25:35 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/02 22:22:34 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <string.h>

int	send_bit(int c, int pid)
{
	static int	shift;

	ft_printf("%c", c);
	if (shift == 8)
		shift = 0;
	if (c & (0x01 << shift))
	{
		kill(pid, SIGUSR2);
	}
	else
	{
		kill(pid, SIGUSR1);
	}
	usleep(100);
	return (shift++);
}

void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR1);
	}
}

void	send_str(int pid, char *msg)
{
	static int	st_pid;
	static int	len;
	static char	*st_msg;
	int			shift;

	if (st_pid == 0)
		st_pid = pid;
	if (!st_msg)
		st_msg = strdup(msg);
	shift = send_bit(st_msg[len], st_pid);
	// ft_printf("%d\n", shift);
	if (shift == 7)
	{
		len++;
	}
	if (len == strlen(st_msg))
	{
		free(st_msg);
		send_null(st_pid);
		exit(0);
	}
	return ;
}

void	handler(int num)
{
	if (num == SIGUSR2)
	{
		ft_printf("here\n");
		send_str(0, NULL);
	}
	if (num == SIGUSR1)
	{
		ft_printf("Message received");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error: incorrect number of arguments.");
		return (1);
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	send_str(atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
