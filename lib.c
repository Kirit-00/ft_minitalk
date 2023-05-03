/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:53:56 by maltun            #+#    #+#             */
/*   Updated: 2023/05/03 07:39:52 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(0, &c, 1);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		digit;
	int		num2;

	num2 = num;
	digit = 0;
	while (num2)
	{
		num2 /= 10;
		digit++;
	}
	str = malloc(sizeof(char));
	str[digit] = 0;
	while (num)
	{
		str[--digit] = 48 + (num % 10);
		num /= 10;
	}
	return (str);
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
		num = (str[i++] - 48) + (num * 10);
	return (num);
}

char	*ft_strjoin(char *s1, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1)
		s1 = malloc(sizeof(char));
	str = malloc(sizeof(char) * ft_strlen(s1) + 1);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = 0;
	free(s1);
	return (str);
}
