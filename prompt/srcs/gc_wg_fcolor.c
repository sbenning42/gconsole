/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_wg_fcolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 21:25:26 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 09:37:28 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole_.h"

void			gc_wg_fcolor_all(int wg_id, int color)
{
	t_cwidget	*w;
	int			x;
	int			y;

	if (!(w = gc_wg_get(wg_id)))
		return ;
	y = -1;
	while (++y < w->height)
	{
		x = -1;
		while (++x < w->width)
		{
			GC_WM_SET(w->map[y][x].attribute, (GC_WM_ATT_SFCOLOR|GC_WM_ATT_MODIFIED));
			w->map[y][x].style.fcolor = color;
		}
	}
}
