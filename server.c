/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:27:10 by omartine          #+#    #+#             */
/*   Updated: 2022/04/18 13:32:17 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	show_pid(int pid)
{
	char	*str_pid;
	int		len_pid;

	str_pid = ft_itoa(pid);
	len_pid = ft_strlen(str_pid);
	write(1, str_pid, len_pid);
	write(1, "\n", 1);
	free(str_pid);
}

void	signal_handler(int signal)
{
	static int	bits;
	static char	c;

	if (!bits)
		bits = 8;
	bits--;
	if (!c)
		c = 0;
	if (signal == SIGUSR1)
		c += 1 << bits;
	if (signal == SIGUSR2)
		c += 0 << bits;
	if (bits == 0)
	{
		if (c == 0)
			write(1, "\n", 1);
		write(1, &c, 1);
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
