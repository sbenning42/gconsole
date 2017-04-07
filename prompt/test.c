/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 15:34:34 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 15:54:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>

int main()
{
	struct timespec	t;

	while (42)
	{
		clock_gettime(CLOCK_REALTIME, &t);
		printf("%ld.%ld\n", t.tv_sec, t.tv_nsec);
	}
	return (0);
}
