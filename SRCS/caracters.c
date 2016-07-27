/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caracters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 17:56:41 by becorbel          #+#    #+#             */
/*   Updated: 2016/07/27 18:48:26 by becorbel         ###   ########.fr       */
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
		type->x = 0;
		type->borne_l = 0;
		type->borne_c = 0;
	}
}
