/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 19:32:17 by becorbel          #+#    #+#             */
/*   Updated: 2016/07/26 19:32:53 by becorbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	**ft_read_bis(int i, int j, int counter, char **data)
{
	while (counter <= i)
	{
		data[counter] = (char*)malloc(sizeof(char) * j + 1);
		if (!(data[counter]))
			return (NULL);
		counter++;
	}
	return (data);
}

char	**ft_read(int i, int j, char **data, char *buff)
{
	int counter;

	counter = 0;
	data = (char**)malloc(sizeof(char*) * i + 1);
	if (!data)
		return (NULL);
	data[counter] = *ft_read_bis(i, j, counter, data);
	i = 0;
	j = 0;
	counter = 0;
	while (buff[counter])
	{
		if (buff[counter] == '\n')
		{
			data[i][j] = '\0';
			counter++;
			j = 0;
			i++;
		}
		data[i][j] = buff[counter];
		counter++;
		j++;
	}
	return (data);
}
