/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:42:44 by omartine          #+#    #+#             */
/*   Updated: 2022/04/18 16:56:54 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_char_signal(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	send_string(t_pd_str *pds)
{
	int	i;

	i = 0;
	while (pds->str[i] != 0)
	{
		handle_char_signal(pds->str[i], pds->pid);
		i++;
	}
	handle_char_signal(pds->str[i], pds->pid);
}

void	num_arg_error(void)
{
	write(1, "Incorrect number of arguments\n", 30);
	exit(0);
}

t_pd_str	*init_struct(char **argv)
{
	t_pd_str	*pds;

	pds = malloc(sizeof(t_pd_str));
	pds->pid = ft_atoi(argv[1]);
	pds->str = str_cpy(argv[2]);
	return (pds);
}

int	main(int argc, char **argv)
{
	t_pd_str	*pds;

	if (argc != 3)
		num_arg_error();
	pds = init_struct(argv);
	send_string(pds);
	free(pds->str);
	free(pds);
	return (0);
}
