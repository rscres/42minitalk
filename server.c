/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:16:03 by rseelaen          #+#    #+#             */
/*   Updated: 2023/08/23 18:25:53 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int num)
{
	num = 0;
	ft_printf("here\n");
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	usleep(0.5 * 10e5);
	ft_printf("Waiting for message...\n");
	pause();
	signal(SIGUSR1, handler);
	return (0);
}
