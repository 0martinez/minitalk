/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:27:10 by omartine          #+#    #+#             */
/*   Updated: 2022/03/03 13:40:13 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_usr(int sign)
{
	if (sign == SIGUSR1)
		printf("SIGUSR1 RECEIVED\n");
	else if (sign == SIGUSR2)
		printf("sigusr2 received\n");
	else
		printf("signal %d\n", sign);
}

int	main(void)
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		printf("can not catch SIGUSR1\n");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		printf("can not catch SIGUSR2\n");
	while (1)
		sleep(1);
}
