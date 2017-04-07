/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 16:44:31 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/09 11:53:45 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gconsole.h"
#include "userlib.h"
#include <time.h>

#define GCOLORSIZE 22

int				g_color[GCOLORSIZE] = {\
	0x0000af,\
	0x005fd7,\
	0x0087af,\
	0x00afaf,\
	0x00d7af,\
	0x00ffaf,\
	0x5fffaf,\
	0x5fafaf,\
	0x5f87af,\
	0x5f5faf,\
	0xd70000,\
	0xd75f00,\
	0xd78700,\
	0xd7af00,\
	0xd7d700,\
	0xd7ff00,\
	0xffff00,\
	0xffd700,\
	0xffaf00,\
	0xff8700,\
	0xff5f00,\
	0xff0000\
};

int				user_hf_display_handler(int id, void *p)
{
	static int	color = 10;

	gc_wg_fcolor_all(id, g_color[color++]);

	color %= GCOLORSIZE;
	return (0);
	(void)p;
}

int				user_marge_display_handler(int id, void *p)
{
	time_t		t;
	char		*ct;
	char		*pwd;
	char		bct[32];
	char		buf[1024];
	int			len;

	t = time(NULL);
	ct = ctime(&t);
	ft_sprintf(bct, "%.9s", ct + 11);
	pwd = ft_getenv("PWD");
	ft_snprintf(buf, 1024, "%25s%-15s%20s%s", " ", bct, " ", pwd);
	len = ft_strlen(buf);

	gc_wg_write(id, buf, len, 0);
	gc_wg_lseek(id, len);

	return (0);
	(void)p;
}

int				user_prompt_display_handler(int id, void *p)
{
	static int	color;

	gc_wg_fcolor_all(id, g_color[color++]);

	color %= GCOLORSIZE;
	return (0);
	(void)p;
}

int				main(int ac, char **av)
{
	t_env		env;
	char		*prompt = "{Awesome !} $> ";
	char		buf[1024];

	ft_sprintf(buf, "%115s", " ");

	if (gc_init(1) < 0)
		return (1);

	env.id[HEAD] = gc_wg_new_s(150, 5, 0, 0);
	env.id[PROMPT] = gc_wg_new_s(15, 1, 0, 6);
	env.id[BODY] = gc_wg_new_s(115, 30, 15, 5);
	env.id[MARGE] = gc_wg_new_s(20, 30, 130, 5);
	env.id[FOOT] = gc_wg_new_s(150, 5, 0, 35);

	gc_wg_set_only_input_handler(user_input_handler);

	gc_wg_set_display_handler(env.id[PROMPT], user_prompt_display_handler);
	gc_wg_set_display_handler(env.id[MARGE], user_marge_display_handler);
	gc_wg_set_display_handler(env.id[HEAD], user_hf_display_handler);
	gc_wg_set_display_handler(env.id[FOOT], user_hf_display_handler);

	gc_wg_write(env.id[PROMPT], prompt, 15, 0);
	gc_wg_write(env.id[BODY], buf, 115, 0);

	gc_wg_fcolor_all(env.id[HEAD], 0x767676);
	gc_wg_fcolor_all(env.id[PROMPT], 0x5f87d7);
	gc_wg_fcolor_all(env.id[BODY], 0x00d7af);
	gc_wg_fcolor_all(env.id[MARGE], 0x005fd7);
	gc_wg_fcolor_all(env.id[FOOT], 0x767676);

	gc_focus((env.focus = BODY));

	gc_loop((void *)&env);

	if (gc_reset() < 0)
		return (1);
	return (0);
	(void)ac;
	(void)av;
}
