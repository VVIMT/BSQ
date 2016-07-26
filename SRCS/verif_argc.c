/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 19:29:11 by becorbel          #+#    #+#             */
/*   Updated: 2016/07/26 19:30:35 by becorbel         ###   ########.fr       */
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
	if (x != (j + 1) * i)
	{
		ft_putstr("map error\n");
		return (0);
	}
	type.borne_l = i;
	type.borne_c = j;
	ft_square(type, -1, NULL, ft_read(i, j, NULL, buff));
	return (0);
}

void	argc_diff_1(int argc, char **argv, int i, int j)
{
	t_struct	type;
	int			x;
	int			k;
	char		*buff;

	k = 0;
	while (++k < argc)
	{
		buff = ft_display(&type, argv, k);
		x = 0;
		i = 0;
		j = 0;
		while (buff[x])
			if (buff[x++] == '\n')
				i++;
		while (buff[j] != '\n')
			j++;
		if (x != (j + 1) * i)
			ft_putstr("map error\n");
		if (x != (j + 1) * i)
			break ;
		type.borne_l = i;
		type.borne_c = j;
		ft_square(type, -1, NULL, ft_read(i, j, NULL, buff));
	}
}
