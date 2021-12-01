# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 17:18:52 by jbadia            #+#    #+#              #
#    Updated: 2021/12/01 11:36:06 by jbadia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CBOLD   = \033[1m
CITALIC = \033[3m
CBLUE   = \033[34m
CVIOLET = \033[35m
NORMAL 	= \033[0m
CBLUEBG   = \033[44m
CVIOLETBG = \033[45m
CWHITEBG  = \033[47m
CGREEN2  = \033[92m
COLOR = $(CBOLD) $(CVIOLET)

NAME = so_long

LIBFT = libft
MAKELIBFT = $(MAKE) -C $(LIBFT)

SRCS_DIR = srcs
CFILES = get_next_line.c get_next_line_utils.c map_utils.c check_map.c move.c \
		texture.c so_long.c utils.c check_map_2.c free_func.c
OFILES = $(CFILES:.c=.o)
HDRS = include

OBJ_DIR = obj

SRCS = $(addprefix $(SRCS_DIR)/, $(CFILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(OFILES))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf


$(OBJ_DIR)/%.o :	$(SRCS_DIR)/%.c
	@${CC} ${CFLAGS} -I ${HDRS} -I $(LIBFT) -c $< -o $@ 
	

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(MAKELIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT) -lft -lmlx -framework OpenGL -framework Appkit -o $@
#	 $(CC) $(CFLAGS) $(OBJS) -L $(LIBFT) -I /usr/local/include -L /usr/local/lib -lX11 -lXext -lm -lmlx -o $@

$(OBJ_DIR) : 
	@mkdir -p $(OBJ_DIR)

all :	$(NAME)
	@echo "$(COLOR)            ___"
	@echo "              __ \ / __ "
	@echo "             /  \ | /  \ "
	@echo "                 \|/ "
	@echo "            _,.---v---._ "
	@echo "   /\__/\  /            \ "
	@echo "   \_  _/ /              \ "
	@echo "     \ \_|           @ __| "
	@echo "      \                \_  $(CITALIC) LET'S PLAY $(COLOR)"
	@echo "       \     ,__/       / "
	@echo "     ~~~\`~~~~~~~~~~~~~~/~~~~ "


clean :
	@$(MAKELIBFT) clean
	@$(RM) $(OBJS)
	
fclean :	clean
	@$(MAKELIBFT) fclean
	@$(RM) $(NAME)
	@echo "$(CBOLD)$(CGREEN2) SO_LONG IS CLEANED $(NORMAL)"

re :	fclean all

.PHONY:	all clean fclean re@echo "