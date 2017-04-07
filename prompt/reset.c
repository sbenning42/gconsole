/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 21:54:13 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 12:49:42 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int ac, char **av)
{
	char	*s;

	if (ac < 2)
		s = "\033[0m";
	else if (av[1][0] == 'h')
		s = "\033[?25h";
	else if (av[1][0] == 'l')
		s = "\033[?25l";
	ft_printf(s);
	return (0);
}