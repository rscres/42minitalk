/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:25:35 by rseelaen          #+#    #+#             */
/*   Updated: 2023/08/23 18:25:56 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error: incorrect number of arguments.");
	}
	kill(atoi(argv[1]), SIGUSR1);
	return (0);
}
