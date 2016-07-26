/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caracters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 17:56:41 by becorbel          #+#    #+#             */
/*   Updated: 2016/07/26 19:36:40 by becorbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <stdio.h>

void	ft_caracters(t_struct *type, char *str, int i)
{
	if (i > 2)
	{
		type->fill = str[i];
		type->obst = str[i - 1];
		type->empty = str[i - 2];
	}
}
