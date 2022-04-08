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

	return (0);
}
