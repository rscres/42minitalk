/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:25:35 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/07 15:39:24 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	return (shift);
}

void	send_str(int pid, char *msg)
{
	static int		st_pid;
	static size_t	len;
	static size_t	total_len;
	static char		*st_msg;
	size_t			shift;

	shift = 0;
	if (st_pid == 0)
		st_pid = pid;
	if (!st_msg)
		st_msg = ft_strdup(msg);
	if (total_len == 0)
		total_len = ft_strlen(st_msg);
	if (len < total_len)
		shift = send_bit(st_msg[len], st_pid);
	else if (len == total_len)
	{
		if (shift == 8 && st_msg)
			free(st_msg);
		shift = send_bit('\0', st_pid);
	}
	if (shift == 8)
		len++;
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
	send_str(ft_atoi(argv[1]), argv[2]);
	while (1)
		sleep(1);
	return (0);
}
