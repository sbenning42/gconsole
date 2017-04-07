/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_wg_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 16:36:35 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/01 16:54:39 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole_.h"

int		gc_wg_write(int wg_id, char *buf, int size, int attribute)
{
	t_cwidget	*w;
	int			i;

	if (!(w = gc_wg_get(wg_id)))
		return (-1);
	if (size > w->offset_diff)
		size = w->offset_diff;
	w->offset_diff -= size;
	i = -1;
	while (++i < size)
	{
		w->map[w->y][w->x].value = buf[i];
		GC_WM_SET(w->map[w->y][w->x].attribute, (GC_WM_EVSET(attribute, GC_WM_ATT_MODIFIED)));
		if ((w->x + 1) >= w->width)
		{
			w->x = 0;
			w->y += 1;
		}
		else
			w->x += 1;
	}
	return (0);
}
