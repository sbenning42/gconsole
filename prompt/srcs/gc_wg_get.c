/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_wg_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 16:01:33 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/01 16:04:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole_.h"

t_cwidget		*gc_wg_get(int wg_id)
{
	t_list		*d;
	t_cwidget	*w;

	d = console()->widget;
	while (d)
	{
		w = (t_cwidget *)d->content;
		if (w->id == wg_id)
			return (w);
		d = d->next;
	}
	return (NULL);
}
