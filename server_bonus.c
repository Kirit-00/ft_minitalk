/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:50:44 by maltun            #+#    #+#             */
/*   Updated: 2023/05/06 00:40:30 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "stdio.h"

char	*g_pid = 0;

void	ft_printpid(void)
{
	char	*str;

	str = ft_itoa(getpid());
	write(0, "Pid -> ", 7);
	write(0, str, sizeof(str));
	free(str);
	write(0, "\n", 1);
}

void	set_feedback_pid(int sig, int *isFinished)
{
	static char	c = 0;
	static int	get_byte = 0;

	if (sig == SIGUSR1)
		c = c | 1;
	if (++get_byte == 8)
	{	
		get_byte = 0;
		if (!c)
			*isFinished = 1;
		g_pid = ft_strjoin(g_pid, c);
		c = 0;
	}
	else
		c <<= 1;
}

void	freepid(int *ispid_null)
{
	int	i;

	i = ft_strlen(g_pid);
	while (i >= 0)
		g_pid[i--] = 0;
	*ispid_null = 0;
}

void	sig_usr(int sig)
{
	static int	ispid_null = 0;
	static char	c = 0;
	static int	get_byte = 0;

	if (ispid_null)
	{
		if (sig == SIGUSR1)
			c = c | 1;
		if (++get_byte == 8)
		{
			get_byte = 0;
			if (!c)
			{
				ft_putchar('\n');
				kill((pid_t)ft_atoi(g_pid), SIGUSR1);
				freepid(&ispid_null);
			}
			ft_putchar(c);
			c = 0;
		}
		else
			c <<= 1;
	}
	else
		set_feedback_pid(sig, &ispid_null);
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
