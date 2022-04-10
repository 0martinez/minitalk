/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:27:10 by omartine          #+#    #+#             */
/*   Updated: 2022/04/08 19:48:37 by omartine         ###   ########.fr       */
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
	char	*str_sig;

	str_sig = ft_itoa(signal);
	write(1, "Received", 8);
	write(1, str_sig, ft_strlen(str_sig));
}

int	main(void)
{
	show_pid(getpid());
	signal(SIGUSR1, signal_handler);
	while (1)
	{
		sleep(2);
		write(1, "SERVER ON\n", 10);
	}
	return (0);
}



	//if (signal(SIGUSR1, sig_usr) == SIG_ERR)
	//	printf("can not catch SIGUSR1\n");
	//if (signal(SIGUSR2, sig_usr) == SIG_ERR)
	//	printf("can not catch SIGUSR2\n");
	//while (1)
	//	sleep(1);
