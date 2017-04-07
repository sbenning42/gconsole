/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 11:31:13 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 16:46:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole_.h"

struct termios		sg_term;

int					putchar_term(int i)
{
	ft_putchar((char)i);
	return (i);
}

int					gc_init_console(int rate)
{
	if (tgetent(NULL, ft_getenv("TERM")) < 0)
		return (-1);
	console()->width = tgetnum("co");
	console()->height = tgetnum("li");
	console()->offset = console()->width * console()->height;
	console()->widget = NULL;
	console()->focus = NULL;
	console()->wsize = 0;
	console()->rate = rate;
	console()->input_handler = NULL;
	console()->display_handler = NULL;
	return (0);
}

int					gc_init_term(int rate)
{
	struct termios	loc;

	if (tcgetattr(0, &sg_term) < 0)
		return (-1);
	loc = sg_term;
	loc.c_lflag &= ~(ICANON|ECHO);
	loc.c_cc[VMIN] = 0;
	loc.c_cc[VTIME] = rate;
	if (tcsetattr(0, TCSADRAIN, &loc) < 0)
		return (-1);
	return (0);
}

int					gc_init(int rate)
{
	int				i;
	int				j;

	if (gc_init_console(rate) < 0)
		return (-1);
	if (!(console()->cmap = (t_widmap **)ft_memalloc(sizeof(t_widmap *) * console()->height)))
		return (-1);
	i = -1;
	while (++i < console()->height)
	{
		if (!(console()->cmap[i] = (t_widmap *)ft_memalloc(sizeof(t_widmap) * console()->width)))
		{
			gc_map_destroy(&console()->cmap, i);
			return (-1);
		}
		j = -1;
		while (++j < console()->width)
			console()->cmap[i][j].value = ' ';
	}
	if (gc_init_term(rate) < 0)
	{
		gc_map_destroy(&console()->cmap, i);
		return (-1);
	}
	ft_printf("{eoc}");
	tputs(tgetstr("cl", NULL), 1, putchar_term);
	return (0);
}

void				gc_wd_lstdestroy(void *content, size_t size)
{
	t_cwidget		*wid;

	wid = (t_cwidget *)content;
	ft_memdel((void **)&wid->map);
	(void)size;
}

int					gc_reset(void)
{
	if (tcsetattr(0, TCSANOW, &sg_term) < 0)
		return (-1);
	if (console()->widget)
		ft_lstdel(&console()->widget, gc_wd_lstdestroy);
	if (console()->cmap)
		gc_map_destroy(&console()->cmap, console()->height);
	tputs(tgetstr("cl", NULL), 1, putchar_term);
	ft_printf("{eoc}GConsole quit\n");
	return (0);
}
