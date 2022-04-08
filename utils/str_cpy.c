/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:25:15 by omartine          #+#    #+#             */
/*   Updated: 2022/04/08 19:28:12 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char	*str_cpy(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!str)
		return (0);
	new_str = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!new_str)
		return (0);
	while (str[i] != 0)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
