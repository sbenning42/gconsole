/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_display_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 20:24:07 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 11:20:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole_.h"

int				gc_display_handler(void *p)
{
	t_list		*d;
	t_cwidget	*w;

	d = console()->widget;
	while (d)
	{
		w = (t_cwidget *)d->content;
		if (w->display_handler)
		{
			if (w->display_handler(w->id, p))
				return (-1);
		}
		d = d->next;
	}
	return (0);
}
