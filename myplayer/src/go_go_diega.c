/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_go_diega.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:00:28 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/04 18:08:11 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				goodbay(t_filler *a)
{
	a->ca = 0;
	while (a->ca < a->map_y)
	{
		free(a->b[a->ca]);
		a->ca++;
	}
	free(a->b);
	close(a->file);
	free(a);
	ft_printf("0 0\n");
	exit(0);
	return (0);
}

void			more_cikl_for_me(t_filler *a)
{
	a->temp = 0;
	a->cty = 0;
	while (a->temp > -200000 && a->cty < a->tet_y)
	{
		a->ctx = 0;
		while (a->temp > -200000 && a->ctx < a->tet_x)
		{
			a->temp += a->b[a->ca + a->cty][a->cb + a->ctx] *
						a->c[a->cty][a->ctx];
			a->ctx++;
		}
		a->cty++;
	}
}

void			free_tetr(t_filler *a)
{
	a->ca = 0;
	while (a->ca < a->tet_y)
	{
		free(a->c[a->ca]);
		a->ca++;
	}
	free(a->c);
}

void			go_go_diega(t_filler *a)
{
	a->best = -200000;
	a->ca = 0;
	while (a->ca < a->pse_y)
	{
		a->cb = 0;
		while (a->cb < a->pse_x)
		{
			more_cikl_for_me(a);
			if (a->best <= a->temp && a->temp < -100)
			{
				a->best = a->temp;
				a->b_y = a->ca - a->real_y;
				a->b_x = a->cb - a->real_x;
			}
			a->cb++;
		}
		a->ca++;
	}
	free_tetr(a);
	if (a->best < -100000)
		goodbay(a);
}
