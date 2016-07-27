/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 18:22:28 by becorbel          #+#    #+#             */
/*   Updated: 2016/07/27 18:23:14 by becorbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_atoi(char *str)
{
	int i;
	int neg;
	int result;

	i = 0;
	result = 0;
	neg = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	if (neg == 1)
		result = result * (-1);
	return (result);
}
