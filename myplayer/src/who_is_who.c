/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_is_who.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:03:40 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/04 21:21:13 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			read_write_trace(t_filler *a)
{
	a->gnl = ft_get_next_line(0, &a->str);
	write(a->file, a->str, ft_strlen(a->str));
	write(a->file, "\n", 1);
}

void			give_tet_array(t_filler *a)
{
	a->ca = 0;
	a->c = (int **)malloc(sizeof(int *) * a->tet_y);
	while (a->ca < a->tet_y)
	{
		a->c[a->ca] = (int *)malloc(sizeof(int) * a->tet_x);
		read_write_trace(a);
		a->cb = 0;
		while (a->cb < a->tet_x)
		{
			if (a->str[a->cb] == '.')
				a->c[a->ca][a->cb] = 0;
			if (a->str[a->cb] == '*')
				a->c[a->ca][a->cb] = 1;
			a->cb++;
		}
		ft_strdel(&(a->str));
		a->ca++;
	}
}

void			read_tetra(t_filler *a, int i)
{
	read_write_trace(a);
	while (!(ft_isdigit(a->str[i])))
		i++;
	a->tet_y = ft_atoi(&(a->str[i]));
	while (ft_isdigit(a->str[i]))
		i++;
	while (!(ft_isdigit(a->str[i])))
		i++;
	a->tet_x = ft_atoi(&(a->str[i]));
	ft_strdel(&(a->str));
	give_tet_array(a);
}

void			read_map(t_filler *a)
{
	read_write_trace(a);
	ft_strdel(&(a->str));
	if (a->first)
	{
		read_write_trace(a);
		ft_strdel(&(a->str));
	}
	a->ca = a->real_y;
	while (a->ca < a->pse_y)
	{
		read_write_trace(a);
		split_str(a);
		ft_strdel(&(a->str));
		a->ca++;
	}
	a->first++;
	find_priority_point_p1(a);
}

void			who_is_who(t_filler *a)
{
	if (a->player == 1)
	{
		a->m1 = 'o';
		a->m2 = 'O';
		a->e1 = 'x';
		a->e2 = 'X';
	}
	else
	{
		a->e1 = 'o';
		a->e2 = 'O';
		a->m1 = 'x';
		a->m2 = 'X';
	}
	ft_strdel(&(a->str));
}
