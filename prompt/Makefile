#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/04/30 16:30:28 by sbenning          #+#    #+#             *#
#*   Updated: 2016/05/02 14:42:52 by sbenning         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =		gconsole

SRC_D =		srcs/

LIB_D =		lib/

OBJ_D =		obj/

HEADER_D =	includes/

SRC =		main.c\
			m42.c\
			gc_init.c\
			gc_loop.c\
			gc_curs_jump.c\
			gc_focus.c\
			gc_attribute.c\
			gc_display_handler.c\
			gc_input_handler.c\
			gc_wg_fcolor.c\
			gc_map.c\
			gc_display.c\
			gc_wg_display.c\
			gc_wg_write.c\
			gc_wg_get.c\
			gc_widget.c\
			gc_wg_map.c\
			gc_console.c\
			user_input_handler.c
			#cg_console.c\
			gc_widget.c\
			gc_loop.c

LIB =		ft

LIBFT_D =	$(addprefix $(LIB_D), $(LIB))

OBJ =		$(SRC:.c=.o)

HEADER =	gconsole_.h

SRC_A =		$(addprefix $(SRC_D), $(SRC))
OBJ_A =		$(addprefix $(OBJ_D), $(OBJ))
HEADER_A =	$(addprefix $(HEADER_D), $(HEADER))
SRC_DEP =	$(addprefix $(SRC_D), %.c)
OBJ_DEP =	$(addprefix $(OBJ_D), %.o)

all : $(NAME)

$(NAME) : $(OBJ_A)
	gcc -Wall -Wextra -o $@ $^ -L$(LIBFT_D) -l$(LIB) -ltermcap -lm

$(OBJ_DEP) : $(SRC_DEP) $(HEADER_A)
	gcc -Wall -Wextra -o $@ -c $< -I $(HEADER_D) -I$(LIBFT_D)/$(HEADER_D)

clean :
	rm -f $(OBJ_A)

fclean : clean
	rm -f $(NAME)

re : fclean all

config :
	mkdir -p $(OBJ_D)
