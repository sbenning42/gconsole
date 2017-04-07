/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 11:32:00 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 19:33:59 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole_.h"
#include <math.h>

void				gc_loop(void *p)
{
	char			buf[32];
	int				ret;
//	struct timespec	spec;
//	long int		old;
//	long int		now;

//	old = 0;
	while (42)
	{
/*		gc_clock()
		clock_gettime(CLOCK_REALTIME, &spec);
		now = spec.tv_sec + (spec.tv_nsec / 1.0e6);
		if (now - old >= 0)
		{
			old = now;
*/			gc_display_handler(p);
			gc_redisplay();
//		}
		ret = read(0, buf, 32);
		if (ret > 0)
		{
			buf[ret] = 0;
			if (gc_input_handler(buf, p))
				break ;
		}
		else if (ret < 0)
			break ;
	}
}
