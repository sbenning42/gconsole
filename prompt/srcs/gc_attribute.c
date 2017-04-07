/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_attribute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 21:39:26 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 16:47:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole_.h"

void	gc_att_apply(int att, int color)
{
	char	buf[1024];
	int		r;
	int		g;
	int		b;

	r = (color >> 16) & 255;
	g = (color >> 8) & 255;
	b = color & 255;
	if (att == 0)
	{
		ft_printf("\033[0m{blank}");
		return ;
	}
	if (GC_WM_IS(att, GC_WM_ATT_SFONT))
	{
		;
	}
	if (GC_WM_IS(att, GC_WM_ATT_SCOLOR))
	{
		;
	}
	if (GC_WM_IS(att, GC_WM_ATT_SFCOLOR))
		ft_sprintf(buf, "\033[48;2;%d;%d;%dm", r,  g, b);
	ft_printf("%s", buf);
}
