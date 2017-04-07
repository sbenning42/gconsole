/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 15:13:09 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/01 15:25:12 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
t_cwidget		*prmt_dup_widget(t_cwidget sample)
{
	t_cwidget	*cp;

	if (!(cp = (t_cwidget *)ft_memalloc(sizeof(t_cwidget))))
		return (NULL);
	*cp = sample;
	return (cp);
}

void			prmt_wid_ifocus(t_cwidget *wid)
{
	int			abs_x;
	int			abs_y;

	abs_x = wid->x_wid + wid->x;
	abs_y = wid->y_wid + wid->y;
	tputs(tgoto(tgetstr("cm", NULL), abs_x, abs_y), 1, pput);
}

void			prmt_wid_fdisplay(t_cwidget *wid)
{
	char		*color;
	char		*eoc;
	char		buf[4096];
	int			size;

	color = wid->fcolor;
	eoc = "{eoc}";
	ft_memset((void *)buf, ' ', 4096);
	size = wid->width * wid->height;
	prmt_wid_ifocus(wid);
	ft_printf(color);
	while (size > 0)
	{
		ft_printf("%.*s", wid->width, buf);
		size -= wid->width;
		prmt_wid_maj_coo(wid, wid->width);
		prmt_wid_ifocus(wid);
	}
	ft_printf(eoc);
	prmt_wid_ifocus(prmtcon()->focus);
}

int				prmt_new_widget(t_cwidget sample)
{
	t_list		*elem;

	if (!(elem = ft_lstnew((void *)&sample, sizeof(t_cwidget))))
		return (-1);
	if (prmtcon()->size == 0)
		prmtcon()->focus = (t_cwidget *)elem->content;
	((t_cwidget *)elem->content)->id = prmtcon()->size;
	prmtcon()->size += 1;
	ft_lstadd(&prmtcon()->widget, elem);
	if (sample.fcolor)
		prmt_wid_fdisplay(&sample);
	return (prmtcon()->size - 1);
}

int				prmt_wid_ifocus_static_write(t_cwidget *wid, char *msg)
{
	int			len;
	int			cp;
	int			tmp;
	int			x_offset;

	len = ft_strlen(msg);
	if (len > (wid->width * wid->height - (wid->y * wid->width + wid->x)))
		len = wid->width * wid->height - (wid->y * wid->width + wid->x);
	cp = len;
	x_offset = wid->width - wid->x;
	while (len > 0 || wid->y == wid->height)
	{
		tmp = (len >= x_offset ? x_offset : len);
		ft_printf("%.*s", tmp, msg);
		msg += tmp;
		len -= tmp;
		prmt_wid_maj_coo(wid, tmp);
		prmt_wid_ifocus(wid);
		x_offset = wid->width;
	}
	prmt_wid_maj_coo(wid, cp * -1);
	return (len);
}

int				prmt_wid_ifocus_write(t_cwidget *wid, char *msg)
{
	int			len;
	int			tmp;
	int			x_offset;

	len = ft_strlen(msg);
	if (len > (wid->width * wid->height - (wid->y * wid->width + wid->x)))
		len = 0;
	x_offset = wid->width - wid->x;
	while (len > 0 && wid->y != wid->height)
	{
		tmp = (len >= x_offset ? x_offset : len);
		ft_printf("%.*s", tmp, msg);
		msg += tmp;
		len -= tmp;
		prmt_wid_maj_coo(wid, tmp);
		prmt_wid_ifocus(wid);
		x_offset = wid->width;
	}
	return (len);
}

t_cwidget		*prmt_wid_get(int id)
{
	t_list		*d;

	d = prmtcon()->widget;
	while (d)
	{
		if (((t_cwidget *)d->content)->id == id)
			return ((t_cwidget *)d->content);
		d = d->next;
	}
	return (NULL);
}

int				prmt_wid_write(int id, char *msg)
{
	t_cwidget	*wid;
	int			success;

	if (!(wid = prmt_wid_get(id)))
		return (-1);
	prmt_wid_ifocus(wid);
	success = prmt_wid_ifocus_write(wid, msg);
	prmt_wid_ifocus(prmtcon()->focus);
	return (success);
}

int				prmt_wid_static_write(int id, char *msg)
{
	t_cwidget	*wid;
	int			success;

	if (!(wid = prmt_wid_get(id)))
		return (-1);
	prmt_wid_ifocus(wid);
	success = prmt_wid_ifocus_static_write(wid, msg);
	prmt_wid_ifocus(prmtcon()->focus);
	return (success);
}

void	prmt_focus(int id)
{
	t_cwidget	*wid;

	wid = prmt_wid_get(id);
	if (wid == NULL)
	{
		return ;
	}
	prmtcon()->focus = wid;
	prmt_wid_ifocus(wid);
}

*/
/*
char				(*g_mode_read[])(void) = {\
	prmt_time_read,\
	prmt_catln_read\
};

int					g_mode[] = {\
	PRMT_M_TIME,\
	PRMT_M_CATLN\
};

typedef struct 		s_coo
{
	int				x;
	int				y;
}					t_coo;

t_coo				*coo(void)
{
	static t_coo	c;

	return (&c);
}

char				prmt_catln_read(void)
{
	return ('c');
}

void				pstime(void)
{
	time_t			t;
	char			*ct;

	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, pput);
	t = time(NULL);
	ct = ctime(&t);
	ft_printf("%.*s ", ft_strlen(ct) - 17, ct + 11);
	tputs(tgoto(tgetstr("cm", NULL), coo()->x, coo()->y), 1, pput);
}

char				prmt_time_read(void)
{*/
/*	char			buf[32];
	int				ret;
	int				i;

	ft_bzero((void *)buf, 32);
	ret = 0;
	while (!ret)
	{
		pstime();
		ret = read(0, buf, 31);
		if (ret < 0)
			return (-1);
		else if (ret)
		{
			buf[ret] = 0;
			if (ret == 1)
				break ;
			i = -1;
			while (++i < ret)
			{
				if (buf[i] == '\033' && buf[i + 1] == '[')
				{
					prmt_maj_coo(ft_printf("[%s]", "CSI"));
					++i;
				}
				else if (ft_isprint(buf[i]))
					prmt_maj_coo(ft_printf("[%c]", buf[i]));
				else
					prmt_maj_coo(ft_printf("[-1]"));
			}
			ret = 0;
		}

	}
	return (*buf);*/
/*	return ('\n');
}

char				prmt_read(int mode)
{
	int				i;

	if (!mode)
		mode |= PRMT_M_TIME;
	i = -1;
	while (++i < PRMT_MSIZE)
	{
		if (g_mode[i] == mode)
			return (g_mode_read[i]());
	}
	return (-1);
}

void				prmt_set_coo(int x, int y)
{
	coo()->x = x;
	coo()->y = y;
}

void				prmt_wid_maj_coo(t_cwidget *wid, int x)
{
	if (x > 0)
	{
		x += wid->x;
		wid->x = x % wid->width;
		wid->y += x / wid->width;
	}
	else if (x < 0)
	{
		x *= -1;
		x += (wid->width - wid->x);
		wid->x = (wid->width - x % wid->width);
		wid->y -= x / wid->width;
	}
}
*/


