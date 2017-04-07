/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 15:11:59 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 16:47:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole_.h"

int					gc_display()
{
	t_list			*d;
	t_cwidget		*w;

	d = console()->widget;
	while (d)
	{
		w = (t_cwidget *)d->content;
		gc_curs_jump(w->x, w->y);
		gc_wg_display(w->id);
		d = d->next;
	}
	if ((w = console()->focus))
		gc_curs_jump(w->x_pos + w->x, w->y_pos + w->y);
	return (0);
}

int				gc_redisplay(void)
{
	t_widmap	**map;
	char		*buf;
	int			x;
	int			y;
	int			i;
	int			att;

	ft_printf("\033[?25l");
	map = console()->cmap;
	if (!(buf = ft_strnew(console()->width)))
		return (-1);
	y = -1;
	while (++y < console()->height)
	{
		gc_curs_jump(0, y);
		att = 0;
		x = -1;
		i = 0;
		while (++x < console()->width)
		{
			if (map[y][x].attribute != att || map[y][x].attribute)
			{
				if (*buf)
				{
					ft_printf("%s", buf);
					ft_bzero((void *)buf, i);
					i = 0;
				}
				att = map[y][x].attribute;
				gc_att_apply(att, map[y][x].style.fcolor);
			}
			buf[i++] = map[y][x].value;
		}
		ft_printf("%s\033[0m{blank}", buf);
		ft_bzero((void *)buf, i);
	}
	ft_printf("\033[0m{blank}\033[?25h");
	ft_memdel((void **)&buf);
	if (console()->focus)
		gc_curs_jump(console()->focus->x_pos + console()->focus->x, console()->focus->y_pos + console()->focus->y);
	return (0);
}
