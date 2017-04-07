/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_wg_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 15:48:54 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 09:37:50 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole_.h"

t_widmap		**gc_wg_map_new(t_cwidget *widget)
{
	t_widmap	**map;
	int			i;

	if (!(map = (t_widmap **)ft_memalloc(sizeof(t_widmap *) * widget->height)))
		return (NULL);
	i = -1;
	while (++i < widget->height)
		map[i] = console()->cmap[i + widget->y_pos] + widget->x_pos;
	return (map);
}
