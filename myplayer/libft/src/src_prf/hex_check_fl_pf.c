/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_check_fl_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:15:42 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/05/19 10:22:31 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void			hex_check_fl_pf(t_tab *a)
{
	if (a->obel_x[3] == 1)
	{
		a->sig = 2;
		a->sym = a->obel_x[10] == 7 ? 'x' : 'X';
	}
}
