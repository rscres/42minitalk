/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:25:35 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/06 12:03:58 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <string.h>

int	send_bit(int c, int pid)
{
	static int	shift;

	if (shift == 8)
		shift = 0;
	if (c & (0x01 << shift++))
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
			exit(1);
	}
	usleep(10);
	return (shift);
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
	if (len <= strlen(st_msg))
		shift = send_bit(st_msg[len], st_pid);
	else if (len == strlen(st_msg) + 1)
	{
		if (st_msg)
			free(st_msg);
		send_bit('\0', st_pid);
	}
	if (shift == 8)
	{
		len++;
	}
	return ;
}

void	handler(int num)
{
	if (num == SIGUSR2)
	{
		send_str(0, NULL);
	}
	if (num == SIGUSR1)
	{
		ft_printf("Message received\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error: incorrect number of arguments.\n");
		return (1);
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_printf("%d\n", strlen(argv[2]));
	send_str(atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
