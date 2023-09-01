/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:25:35 by rseelaen          #+#    #+#             */
/*   Updated: 2023/09/01 20:19:38 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	to_binary(int c, int pid)
{
	int	shift;

	shift = -1;
	while (++shift < 8)
	{
		if (c & (0x01 << shift))
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		usleep(100);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	len;

	if (argc != 3)
	{
		ft_printf("Error: incorrect number of arguments.");
		return (1);
	}
	len = 0;
	while (argv[2][len])
	{
		to_binary(argv[2][len++], atoi(argv[1]));
	}
	ft_printf("%d\n", len);
	return (0);
}
