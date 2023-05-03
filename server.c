/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:50:44 by maltun            #+#    #+#             */
/*   Updated: 2023/05/02 22:55:20 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_printpid(void)
{
	char	*str;

	str = ft_itoa(getpid());
	write(0, "Pid -> ", 7);
	write(0, str, sizeof(str));
	free(str);
	write(0, "\n", 1);
}

void	sig_usr(int sig)
{
	static char	str = 0;
	static int	get_byte = 0;

	if (sig == SIGUSR1)
		str = str | 1;
	if (++get_byte == 8)
	{
		get_byte = 0;
		if (!str)
			ft_putchar('\n');
		ft_putchar(str);
		str = 0;
	}
	else
		str <<= 1;
}

int	main(void)
{
	ft_printpid();
	signal(SIGUSR1, sig_usr);
	signal(SIGUSR2, sig_usr);
	while (1)
		pause();
	return (0);
}
