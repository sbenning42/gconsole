/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 20:35:15 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 13:32:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERLIB_H
# define USERLIB_H

# define HEAD 0
# define MARGE 1
# define BODY 2
# define PROMPT 3
# define FOOT 4

typedef struct s_env
{
	int			id[5];
	int			focus;
}				t_env;

# include "gconsole.h"

int		user_input_handler(char *input, void *p);
int		user_header_display_handler(int id, void *p);

#endif
