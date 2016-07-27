/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 18:20:40 by becorbel          #+#    #+#             */
/*   Updated: 2016/07/27 20:17:57 by becorbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	*ft_create_str_stdin(t_struct *type)
{
	int			i;
	int			ret;
	char		buff[BUFF_SIZE];
	char		*str;

	ret = 0;
	str = (char*)malloc(sizeof(char) * 2);
	while ((ret = read(0, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		str = ft_strcat(str, buff);
	}
	i = 0;
	while (str[i] != '\n')
		i++;
	ft_caracters(type, str, i - 1);
	return (str + i + 1);
}

char	*ft_display(t_struct *type, char **argv, int k)
{
	int		i;
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE];
	char	*str;

	fd = open(argv[k], O_RDONLY);
	str = malloc(sizeof(char) * 2);
	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		buff[ret] = '\0';
		str = ft_strcat(str, buff);
	}
	i = 0;
	while (str[i] != '\n')
		i++;
	check_first_line(type, 0, buff);
	ft_caracters(type, str, i - 1);
	close(fd);
	if ((str[i + 1]) != '\0')
		return (str + i + 1);
	return (NULL);
}

void	check_first_line(t_struct *type, int i, char *buff)
{
	int				j;
	int				k;
	char			*nb;

	j = 0;
	k = 0;
	while (buff[j] != '\n')
		j++;
	k = j + 1;
	while (buff[k])
		if (buff[k++] == '\n')
			i++;
	j = j - 3;
	nb = malloc(sizeof(char) * (j + 1));
	k = 0;
	while (k < j)
	{
		nb[k] = buff[k];
		k++;
	}
	nb[k] = '\0';
	if (ft_atoi(nb) == i && ft_atoi(nb) > 0)
		type->valid = 1;
	else
		type->valid = 0;
}
