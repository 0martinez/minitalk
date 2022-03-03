/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:02:30 by omartine          #+#    #+#             */
/*   Updated: 2022/03/03 18:01:46 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_itoa(char *str)
{
	int	num;
	int	simb;

	num = 0;
	simb = 1;
	if (str[0] == '-')
		simb = -1;

}

void	ft_putnbr(char *str)
{
	int	i;
	int	len;
	int	smb;

	i = 0;
	smb = 1;
	len = ft_strlen(str);
	if (str[0] == '-')
		smb = -1;

}
