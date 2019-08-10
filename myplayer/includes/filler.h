/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonnor- <ldonnor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 09:36:51 by ldonnor-          #+#    #+#             */
/*   Updated: 2019/07/04 18:09:38 by ldonnor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "mlx.h"
# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

typedef struct			s_filler
{
	int					player;
	char				*str;
	int					**b;
	int					**c;
	int					map_x;
	int					map_y;
	int					real_x;
	int					real_y;
	int					pse_x;
	int					pse_y;
	int					tet_x;
	int					tet_y;
	int					cty;
	int					ctx;
	int					temp;
	int					traces;
	int					gnl;
	char				m1;
	char				m2;
	char				e1;
	char				e2;
	int					ca;
	int					cb;
	int					cc;
	int					max;
	int					now;
	int					prew;
	int					zero;
	int					best;
	int					b_x;
	int					b_y;
	int					first;
	int					file;
}						t_filler;

void					go_go_diega(t_filler *a);
void					free_tetr(t_filler *a);
void					more_cikl_for_me(t_filler *a);
int						goodbay(t_filler *a);

void					split_str(t_filler *a);
void					paint_max(t_filler *a);
void					paint_now(t_filler *a);
void					find_priority_point_p2(t_filler *a);
void					find_priority_point_p1(t_filler *a);

void					read_write_trace(t_filler *a);
void					give_tet_array(t_filler *a);
void					read_tetra(t_filler *a, int i);
void					read_map(t_filler *a);
void					who_is_who(t_filler *a);

void					init_struckt(t_filler *a);
void					who_am_i(t_filler *a);
void					create_array(t_filler *a);
void					map_size(t_filler *a, int i);

#endif
