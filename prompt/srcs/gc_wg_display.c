/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_wg_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 15:11:03 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/01 22:02:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole_.h"

int				gc_wg_display(int wg_id)
{
	t_cwidget	*widget;
	int			x;
	int			y;

	if (!(widget = gc_wg_get(wg_id)))
		return (-1);
	y = -1;
	while (++y < widget->height)
	{
		x = -1;
		while (++x < widget->width)
		{
			if (GC_WM_IS(widget->map[y][x].attribute, GC_WM_ATT_MODIFIED))
			{
				gc_curs_jump(widget->x_pos + x, widget->y_pos + y);
				ft_printf("%c", widget->map[y][x].value);
				GC_WM_UNSET(widget->map[y][x].attribute, GC_WM_ATT_MODIFIED);
			}
		}
	}
	return (0);
}
