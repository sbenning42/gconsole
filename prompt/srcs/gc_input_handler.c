/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 15:12:38 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 10:36:11 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole_.h"

int		gc_input_handler(char *input, void *p)
{
	t_list		*d;
	t_cwidget	*w;

	if (console()->input_handler)
		return (console()->input_handler(input, p));
	d = console()->widget;
	while (d)
	{
		w = (t_cwidget *)d->content;
		if (w->input_handler)
			return (w->input_handler(w->id, input, p));
		d = d->next;
	}
	return (0);
}

int		gc_wg_set_only_input_handler(int (*handler)(char *, void *))
{
	console()->input_handler = handler;
	return (0);
}
