/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_focus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 20:45:28 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 10:15:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole_.h"

void		gc_wg_focus(t_cwidget *widget)
{
	gc_curs_jump(widget->x + widget->x_pos, widget->y + widget->y_pos);
}

int			gc_focus(int wg_id)
{
	t_cwidget	*w;

	if (!(w = gc_wg_get(wg_id)))
		return (-1);
	gc_wg_focus((console()->focus = w));
	return (wg_id);
}
