/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 19:29:11 by becorbel          #+#    #+#             */
/*   Updated: 2016/07/27 23:34:31 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		argc1(void)
{
	int			i;
	int			j;
	int			x;
	char		*buff;
	t_struct	type;

	buff = ft_create_str_stdin(&type);
	i = 0;
	j = 0;
	x = 0;
	while (buff[x])
		if (buff[x++] == '\n')
			i++;
	while (buff[j] != '\n')
		j++;
	if ((x != (j + 1) * i) || (type.valid == 0))
	{
		write(2, "map error\n", 10);
		return (0);
	}
	type.borne_l = i;
	type.borne_c = j;
	ft_square(type, -1, NULL, ft_read(i, j, NULL, buff));
	return (0);
}

int		argc_diff_1(char *buff, int argc, char **argv, int k)
{
	t_struct	type;

	type.argc = argc;
	while (++k < type.argc)
	{
		if (ft_display(&type, argv, k) == NULL)
			write(2, "map error\n", 10);
		if (ft_display(&type, argv, k) == NULL)
			return (0);
		buff = ft_display(&type, argv, k);
		yo(&type);
		while (buff[type.y])
			if (buff[(type.y)++] == '\n')
				(type.i)++;
		while (buff[type.j] != '\n')
			(type.j)++;
		if (type.y != (type.j + 1) * type.i || (type.valid == 0))
			write(2, "map error\n", 10);
		if (type.y != (type.j + 1) * type.i || (type.valid == 0))
			return (0);
		type.borne_l = type.i;
		type.borne_c = type.j;
		ft_square(type, -1, NULL, ft_read(type.i, type.j, NULL, buff));
	}
	return (0);
}

void	yo(t_struct *type)
{
	type->y = 0;
	type->i = 0;
	type->j = 0;
}
