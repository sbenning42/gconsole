/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_widget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 11:34:47 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 11:11:19 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole_.h"


int				gc_wg_lseek(int wg_id, int offset)
{
	t_cwidget	*w;
	int			i;

	if (!(w = gc_wg_get(wg_id)))
		return (-1);
	w->offset_diff += offset;
	i = -1;
	while (++i < offset)
	{
		if (w->x - 1 < 0)
		{
			w->y -= 1;
			w->x = w->width - 1;
		}
		else
			w->x -= 1;
	}
	return (0);
}

t_cwidget		gc_wg_new_sample(int width, int height, int x_pos, int y_pos)
{
	t_cwidget	sample;

	sample.id = console()->wsize;
	sample.offset = width * height;
	sample.width = width;
	sample.height = height;
	sample.x_pos = x_pos;
	sample.y_pos = y_pos;
	sample.clock = console()->rate;
	sample.rate = sample.clock;
	sample.offset_diff = width * height;
	sample.x = 0;
	sample.y = 0;
	sample.display_handler = NULL;
	sample.input_handler = NULL;
	return (sample);
}

int				gc_wg_new(int width, int height, int x_pos, int y_pos)
{
	t_list		*elem;
	t_cwidget	*w;
	t_cwidget	sample;

	sample = gc_wg_new_sample(width, height, x_pos, y_pos);
	if (!(elem = ft_lstnew((void *)&sample, sizeof(t_cwidget))))
		return (-1);
	w = (t_cwidget *)elem->content;
	if (!(w->map = gc_wg_map_new(w)))
	{
		ft_memdel((void **)&elem);
		return (-1);
	}
	if (!console()->focus)
		console()->focus = w;
	ft_lstadd(&console()->widget, elem);
	console()->wsize += 1;
	return (w->id);
}

int				gc_wg_new_s(int width, int height, int x_pos, int y_pos)
{
	int			id;

	id = gc_wg_new(width, height, x_pos, y_pos);
	if (id < 0)
	{
		gc_reset();
		ft_exit(EXIT_FAILURE, "error in gc_wg_new");
	}
	return (id);
}

int			gc_wg_set_display_handler(int wg_id, int (*handler)(int, void *))
{
	t_cwidget	*w;

	if (!(w = gc_wg_get(wg_id)))
		return (-1);
	w->display_handler = handler;
	return (0);
}

