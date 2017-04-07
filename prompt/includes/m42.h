/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m42.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 17:36:00 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/30 17:49:50 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M42_H
# define M42_H

# include "libft.h"

# define M42INIT g_m42 = 0
# define M42IS(X) ((X & g_m42) == X)
# define M42SET(X) g_m42 |= X
# define M42USET(X) g_m42 &= ~X

# define M42_VERBOSE 0x1
# define M42_COLOR 0x2

extern long int		g_m42;

#endif
