/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 11:15:14 by becorbel          #+#    #+#             */
/*   Updated: 2016/07/26 19:36:37 by becorbel         ###   ########.fr       */
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
		str = ft_strcat(str, buff[ret]);
	}
	str[ret] = 0;
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
		str = ft_strcat(str, buff[ret]);
	}
	i = 0;
	while (str[i] != '\n')
		i++;
	ft_caracters(type, str, i - 1);
	close(fd);
	return (str + i + 1);
}
