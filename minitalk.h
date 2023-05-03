/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:50:54 by maltun            #+#    #+#             */
/*   Updated: 2023/05/03 07:22:42 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_itoa(int num);
int		ft_atoi(char *str);
void	ft_putchar(char c);
char	*ft_strjoin(char *s1, char c);
int		ft_strlen(char *str);

#endif
