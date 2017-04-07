/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 14:17:41 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/01 14:21:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole_.h"

void		gc_map_destroy(t_widmap ***map, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		ft_memdel((void **)((*map) + i));
	ft_memdel((void **)map);
}
