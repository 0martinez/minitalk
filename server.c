/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:27:10 by omartine          #+#    #+#             */
/*   Updated: 2022/04/18 17:09:24 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*add_to_string(char *str, char c)
{
	char	*new_str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	new_str = (char *) malloc(sizeof(char) * len + 2);
	if (!new_str)
	{
		write(1, "Malloc error", 12);
		exit(0);
	}
	while (i != len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = 0;
	free(str);
	return (new_str);
}

void	show_pid(int pid)
{
	char	*str_pid;
	int		len_pid;

	str_pid = ft_itoa(pid);
	len_pid = ft_strlen(str_pid);
	write(1, "SERVER PID: ", 12);
	write(1, str_pid, len_pid);
	write(1, "\n", 1);
	free(str_pid);
}

char	*print_string(char *str)
{
	write(1, str, ft_strlen(str));
	free(str);
	write(1, "\n", 1);
	str = 0;
	return (str);
}

void	signal_handler(int signal)
{
	static int	bits;
	static char	c;
	static char	*str;

	if (!bits)
		bits = 8;
	if (!c)
		c = 0;
	bits--;
	if (signal == SIGUSR1)
		c += 1 << bits;
	if (signal == SIGUSR2)
		c += 0 << bits;
	if (bits == 0)
	{
		if (c == 0)
			str = print_string(str);
		else
			str = add_to_string(str, c);
		c = 0;
	}
}

int	main(void)
{
	show_pid(getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		sleep(2);
	return (0);
}
