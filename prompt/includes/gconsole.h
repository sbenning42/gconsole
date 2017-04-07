/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gconsole.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 11:36:36 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/02 11:11:22 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GCONSOLE_H
# define GCONSOLE_H

# define GC_WM_IS(X, Y) ((X & Y) == Y)
# define GC_WM_EVSET(X, Y) (X | Y)
# define GC_WM_EVUNSET(X, Y) (X & ~Y)
# define GC_WM_SET(X, Y) X = GC_WM_EVSET(X, Y)
# define GC_WM_UNSET(X, Y) X = GC_WM_EVUNSET(X, Y)
# define GC_WM_TRIG(X, Y) X = (GC_WM_IS(X, Y) ? GC_WM_EVUNSET(X, Y) : GC_WM_EVSET(X, Y))

/*###	OCTET 1	: INFO	###*/

# define GC_WM_MASK_INFO(X) (X & 0xff)

# define GC_WM_ATT_MODIFIED 0x1
# define GC_WM_ATT_STYLE 0x2

# define GC_WM_ATT_SFONT 0x10
# define GC_WM_ATT_SCOLOR 0x20
# define GC_WM_ATT_SFCOLOR 0x40

/*###	OCTET 2	: FONT STYLE	###*/

# define GC_WM_MASK_SFONT(X) ((X << 0xff) & 0xff)

/*###	OCTET 3	: COLOR STYLE	###*/

# define GC_WM_MASK_COLOR(X) ((X << 0xffff) & 0xff)

/*###	OCTET 4 : FCOLOR STYLE		###*/

# define GC_WM_MASK_FCOLOR(X) ((X << 0xffffff) & 0xff)

/*###	OCTET 5 :		###*/
/*###	OCTET 6 :		###*/
/*###	OCTET 7 :		###*/
/*###	OCTET 8 :		###*/

# include "m42.h"
# include "libft.h"
# include <term.h>
# include <time.h>

/*		gc_ : Graphic Console		*/

int			gc_init(int rate);
int			gc_reset(void);

void		gc_loop(void *p);
int			gc_input_handler(char *input, void *p);

int			gc_read(char *buf, size_t size);
int			gc_display(void);
int			gc_redisplay(void);
int			gc_clear(void);
int			gc_clear_att(void);
int			gc_clear_val(void);

/*		wg_ : WidGet		*/

int			gc_wg_new(int width, int height, int x_pos, int y_pos);
int			gc_wg_new_s(int width, int height, int x_pos, int y_pos);

int			gc_wg_destroy(int wg_id);

int			gc_wg_set_only_input_handler(int (*handler)(char *, void *));
int			gc_wg_set_display_handler(int wg_id, int (*handler)(int, void *));

int			gc_focus(int wg_id);

int			gc_wg_rate(int wg_id, int rate);

int			gc_wg_lseek(int wg_id, int offset);
int			gc_wg_lseek_reset(int wg_id);

int			gc_wg_write(int wg_id, char *buf, int size, int attribute);
int			gc_wg_static_write(int wg_id, char *buf, size_t size, int attribute);
int			gc_wg_display(int wg_id);
int			gc_wg_redisplay(int wg_id);
int			gc_wg_clear(int wg_id);
int			gc_wg_clear_att(int wg_id);
int			gc_wg_clear_val(int wg_id);

void		gc_wg_fcolor_all(int wg_id, int color);

#endif
