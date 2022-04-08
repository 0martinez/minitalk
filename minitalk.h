/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:52:57 by omartine          #+#    #+#             */
/*   Updated: 2022/04/08 19:32:20 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct pd_str
{
	int		pid;
	char	*str;
}	t_pd_str;

void	ft_putstr(char *str);
void	ft_putchar(char c);
char	*ft_itoa(int n);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
char	*str_cpy(char *str);
#endif
