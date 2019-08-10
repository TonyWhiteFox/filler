/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:37:25 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/04 18:08:31 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			map_size(t_filler *a, int i)
{
	while (!(ft_isdigit(a->str[i])))
		i++;
	a->real_y = ft_atoi(&(a->str[i]));
	while (ft_isdigit(a->str[i]))
		i++;
	while (!(ft_isdigit(a->str[i])))
		i++;
	a->real_x = ft_atoi(&(a->str[i]));
	a->map_x = a->real_x * 3 + 10;
	a->map_y = a->real_y * 3 + 10;
	a->pse_x = a->real_x * 2;
	a->pse_y = a->real_y * 2;
	if (a->real_x > a->real_y)
		a->max = a->real_x * 2;
	else
		a->max = a->real_y * 2;
	ft_strdel(&(a->str));
}

void			create_array(t_filler *a)
{
	a->ca = 0;
	a->b = (int **)malloc(sizeof(int *) * a->map_y);
	while (a->ca < a->map_y)
	{
		a->b[a->ca] = (int *)malloc(sizeof(int) * a->map_x);
		a->cb = 0;
		while (a->cb < a->map_x)
		{
			if ((a->ca < a->real_y) || (a->ca > a->pse_y - 1) ||
					(a->cb < a->real_x) || (a->cb > a->pse_x - 1))
				a->b[a->ca][a->cb] = -400000;
			else
				a->b[a->ca][a->cb] = 0;
			a->cb++;
		}
		a->ca++;
	}
}

void			who_am_i(t_filler *a)
{
	int			i;

	i = 0;
	read_write_trace(a);
	while (!ft_isdigit(a->str[i]))
		i++;
	a->player = a->str[i] - '0';
	who_is_who(a);
	read_write_trace(a);
	map_size(a, 0);
	create_array(a);
}

void			init_struckt(t_filler *a)
{
	a->player = 0;
	a->real_x = 0;
	a->real_y = 0;
	a->gnl = 1;
	a->file = creat("ldonnor.txt", 00777);
	who_am_i(a);
}

int				main(void)
{
	t_filler	*a;

	if (!(a = (t_filler *)malloc(sizeof(a))))
		return (1);
	init_struckt(a);
	a->first = 0;
	while (1)
	{
		read_map(a);
		read_tetra(a, 0);
		go_go_diega(a);
		ft_printf("%i %i\n", a->b_y, a->b_x);
	}
	exit(0);
	return (0);
}
