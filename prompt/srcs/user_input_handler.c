/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 20:30:41 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 13:32:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "userlib.h"

int		user_input_handler(char *input, void *p)
{
	t_env	*e;

	e = (t_env *)p;
	if (ft_isprint(*input))
		gc_wg_write(e->id[BODY], input, 1, 0);
	else if (*input == '\n')
		return (1);
	return (0);
}
