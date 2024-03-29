/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_val_pf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:43:49 by andrewkirpi       #+#    #+#             */
/*   Updated: 2019/05/19 10:58:11 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void			zero_val_pf(t_tab *a)
{
	a->sig = 0;
	a->len = 0;
	a->full = 0;
	a->zero = 0;
	a->stop = 0;
	a->space = 0;
	a->len_num = 0;
	a->count_m = 0;
	a->sym = ' ';
	a->mass = NULL;
}
