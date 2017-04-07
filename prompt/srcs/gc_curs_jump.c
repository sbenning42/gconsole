/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_curs_jump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 16:21:43 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/01 20:49:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole_.h"

void		gc_curs_jump(int x, int y)
{
	if (x < 0 || x >= console()->width)
		return ;
	if (y < 0 || y >= console()->height)
		return ;
	tputs(tgoto(tgetstr("cm", NULL), x, y),1, putchar_term);
}
