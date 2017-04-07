/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gconsole_.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 11:35:56 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 10:34:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GCONSOLE__H
# define GCONSOLE__H

#include "gconsole.h"

typedef struct		s_swidmap
{
	int				font;
	int				color;
	int				fcolor;
}					t_swidmap;

typedef struct		s_widmap
{
	char			value;
	long int		attribute;
	t_swidmap		style;
}					t_widmap;

typedef struct		s_cwidget
{
	int				id;
	int				offset;
	int				width;
	int				height;
	int				x_pos;
	int				y_pos;
	int				clock;
	int				rate;
	int				offset_diff;
	int				x;
	int				y;
	t_widmap		**map;
	int				(*display_handler)(int, void *);
	int				(*input_handler)(int, char *, void *);
}					t_cwidget;

typedef struct		s_gconsl
{
	int				offset;
	int				width;
	int				height;
	t_list			*widget;
	size_t			wsize;
	t_cwidget		*focus;
	t_widmap		**cmap;
	int				rate;
	int				(*display_handler)(void *);
	int				(*input_handler)(char *, void *);
}					t_gconsl;

t_gconsl			*console(void);

int					putchar_term(int i);

int					gc_display_handler(void *p);
void				gc_att_apply(int att, int color);

void				gc_wg_focus(t_cwidget *widget);
void				gc_map_destroy(t_widmap ***map, int size);
t_cwidget			*gc_wg_get(int wg_id);
void				gc_curs_jump(int x, int y);

t_widmap			**gc_wg_map_new(t_cwidget *widget);
void				gc_wg_lstdestroy(void *content, size_t size);

#endif
