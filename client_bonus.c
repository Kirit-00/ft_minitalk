/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:51:08 by maltun            #+#    #+#             */
/*   Updated: 2023/05/03 07:23:37 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendmypid(int pid)
{
	int		i;
	char	c;
	char	*str;

	str = ft_itoa(getpid());
	while (*str)
	{
		i = 8;
		c = *(str++);
		while (i--)
		{
			if (c >> i & 1)
				kill((pid_t)pid, SIGUSR1);
			else
				kill((pid_t)pid, SIGUSR2);
			usleep(50);
		}
	}
	i = 8;
	while (i--)
	{
		kill((pid_t)pid, SIGUSR2);
		usleep(50);
	}
}

void	ft_kill(int pid, char *str)
{
	int		i;
	char	c;

	sendmypid(pid);
	while (*str)
	{
		i = 8;
		c = *(str++);
		while (i--)
		{
			if (c >> i & 1)
				kill((pid_t)pid, SIGUSR1);
			else
				kill((pid_t)pid, SIGUSR2);
			usleep(50);
		}
	}
	i = 8;
	while (i--)
	{
		kill((pid_t)pid, SIGUSR2);
		usleep(50);
	}
}

void	ft_sigusr(int sigusr)
{
	if (sigusr == SIGUSR1)
		write(1, "Success signal received !\n", 26);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(0, "invalid arguments please try again", 34);
		return (0);
	}
	signal(SIGUSR1, ft_sigusr);
	ft_kill(ft_atoi(argv[1]), argv[2]);
}
