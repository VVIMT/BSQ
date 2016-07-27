/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:06:45 by becorbel          #+#    #+#             */
/*   Updated: 2016/07/27 23:06:34 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_square_bis(int *p, int i, int j, int carre)
{
	if (carre > p[0])
	{
		p[1] = i;
		p[2] = j;
		p[0] = carre;
	}
}

void	ft_square(t_struct type, int carre, int *p, char **buff)
{
	int i;
	int j;

	i = -1;
	p = tableau(&carre, 0, 0);
	while (buff[++i][0])
	{
		j = -1;
		while (buff[i][++j])
		{
			type.x = 0;
			if (buff[i][j] == type.empty
				&& (i + p[0]) < type.borne_l && (j + p[0]) < type.borne_c)
			{
				carre = ft_check(i, j, type, buff);
				ft_square_bis(p, i, j, carre);
				if (j + carre >= type.borne_c - 1 && type.borne_c > 1)
					j = type.borne_c - 1;
			}
		}
	}
	ft_replace(p, type, buff);
}

int		*tableau(int *carré, int i, int j)
{
	int *tab;

	tab = (int*)malloc(sizeof(*tab) * 3);
	if (!tab)
		return (NULL);
	tab[0] = *carré;
	tab[1] = i;
	tab[2] = j;
	return (tab);
}

void	ft_replace(int *p, t_struct type, char **buff)
{
	int m;
	int n;

	m = p[1];
	while (m <= p[1] + p[0] && p[1] + p[0] <= type.borne_l)
	{
		n = p[2];
		while (n <= p[2] + p[0] && p[2] + p[0] <= type.borne_c)
		{
			buff[m][n] = type.fill;
			n++;
		}
		m++;
	}
	ft_print(buff);
}

int		ft_check(int i, int j, t_struct type, char **buff)
{
	int k;
	int l;

	k = type.x;
	while (buff[i + k][j + type.x] != type.obst
			&& k > 0 && i + k <= type.borne_l)
		k--;
	l = type.x;
	while (buff[i + type.x][j + l] != type.obst
			&& l > 0 && j + k <= type.borne_c)
		l--;
	if (k > 0 || l > 0 || buff[i + k][j + type.x] == type.obst
			|| buff[i + type.x][j + l] == type.obst)
		return (type.x - 1);
	else if (k == 0 && l == 0 && buff[i + type.x][j + l] == type.empty
			&& buff[i + k][j + type.x] == type.empty
			&& (i + type.x + 1) < type.borne_l
			&& (j + type.x + 1) < type.borne_c)
	{
		type.x = type.x + 1;
		return (ft_check(i, j, type, buff));
	}
	else
		return (type.x);
	return (0);
}
