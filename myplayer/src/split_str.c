/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:02:34 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/04 18:14:07 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			split_str(t_filler *a)
{
	a->cc = 0;
	while (ft_isdigit(a->str[a->cc]) || a->str[a->cc] == ' ')
		a->cc++;
	a->cb = a->real_x;
	while (a->cb < a->pse_x)
	{
		if (a->str[a->cc] == a->m1 || a->str[a->cc] == a->m2)
			a->b[a->ca][a->cb] = -100000;
		else if (a->str[a->cc] == a->e1 || a->str[a->cc] == a->e2)
			a->b[a->ca][a->cb] = -200000;
		else if (a->str[a->cc] == '.')
			a->b[a->ca][a->cb] = 0;
		a->cb++;
		a->cc++;
	}
}

void			paint_max(t_filler *a)
{
	if (a->b[a->ca][a->cb - 1] >= 0)
	{
		a->b[a->ca][a->cb - 1] = a->max;
		a->zero--;
	}
	if (a->b[a->ca][a->cb + 1] >= 0)
	{
		a->b[a->ca][a->cb + 1] = a->max;
		a->zero--;
	}
	if (a->b[a->ca - 1][a->cb] >= 0)
	{
		a->b[a->ca - 1][a->cb] = a->max;
		a->zero--;
	}
	if (a->b[a->ca + 1][a->cb] >= 0)
	{
		a->b[a->ca + 1][a->cb] = a->max;
		a->zero--;
	}
}

void			paint_now(t_filler *a)
{
	if (a->b[a->ca][a->cb - 1] == 0)
	{
		a->b[a->ca][a->cb - 1] = a->now;
		a->zero--;
	}
	if (a->b[a->ca][a->cb + 1] == 0)
	{
		a->b[a->ca][a->cb + 1] = a->now;
		a->zero--;
	}
	if (a->b[a->ca - 1][a->cb] == 0)
	{
		a->b[a->ca - 1][a->cb] = a->now;
		a->zero--;
	}
	if (a->b[a->ca + 1][a->cb] == 0)
	{
		a->b[a->ca + 1][a->cb] = a->now;
		a->zero--;
	}
}

void			find_priority_point_p2(t_filler *a)
{
	while (a->now > 0)
	{
		a->prew = a->now + 1;
		a->ca = a->real_y;
		while (a->ca < a->pse_y)
		{
			a->cb = a->real_x;
			while (a->cb < a->pse_x)
			{
				if (a->b[a->ca][a->cb] == a->prew)
					paint_now(a);
				a->cb++;
			}
			a->ca++;
		}
		a->now--;
	}
}

void			find_priority_point_p1(t_filler *a)
{
	a->zero = 0;
	a->ca = a->real_y;
	while (a->ca < a->pse_y)
	{
		a->cb = a->real_x;
		while (a->cb < a->pse_x)
		{
			if (a->b[a->ca][a->cb] == 0)
				a->zero++;
			if (a->b[a->ca][a->cb] == -200000)
				paint_max(a);
			a->cb++;
		}
		a->ca++;
	}
	a->now = a->max - 1;
	find_priority_point_p2(a);
}
