/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:42:44 by omartine          #+#    #+#             */
/*   Updated: 2022/04/08 19:43:31 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	handle_char_signal(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1 == 1)
			kill(SIGUSR1, pid);
		else
			kill(SIGUSR2, pid);
		i++;
	}
}	

void	send_string(t_pd_str *pds)
{
	int	i;

	i = 0;
	if (str_checker(pds->str) == 0)
	{
		write (1, "Non valid characters on the string", 34);
		free(pds->str);
		exit (0);
	}
	while (pds->str[i] != 0)
	{
		handle_char_signal(pds->str[i], pds->pid);
		i++;
	}
}

void	num_arg_error(void)
{
	write(1, "Incorrect number of arguments", 29);
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
	printf("%d----%s", pds->pid, pds->str);
	//send_string(pds);
	return (0);
}
