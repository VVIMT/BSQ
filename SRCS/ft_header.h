/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becorbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 12:31:59 by becorbel          #+#    #+#             */
/*   Updated: 2016/07/27 23:35:00 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# define BUFF_SIZE 8000000

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_struct
{
	int			argc;
	int			borne_l;
	int			borne_c;
	int			x;
	int			y;
	int			i;
	int			j;
	int			valid;
	char		empty;
	char		obst;
	char		fill;
}				t_struct;

void			check_first_line(t_struct *type, int i, char *buff);
int				ft_atoi(char *str);
void			ft_caracters(t_struct *type, char *str, int i);
char			*ft_strcat(char *s1, char *s2);
int				check_argc(int argc, char **argv, char *buff);
char			*ft_create_str_stdin(t_struct *type);
char			*ft_display(t_struct *type, char **argv, int k);
int				ft_strlen(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_print(char **data);
char			**ft_read(int i, int j, char **data, char *buff);
char			**ft_read_bis(int i, int j, int counter, char **data);
void			ft_square(t_struct type, int carré, int *p, char **buff);
void			ft_square_bis(int *p, int i, int j, int carre);
int				argc1(void);
int				argc_diff_1(char *buff, int argc, char **argv, int k);
void			yo(t_struct *type);
int				*tableau(int *carré, int i, int j);
void			ft_replace(int *p, t_struct type, char **buff);
int				ft_check(int i, int j, t_struct type, char **buff);

#endif
