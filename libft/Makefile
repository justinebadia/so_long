# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 11:08:17 by jbadia            #+#    #+#              #
#    Updated: 2021/12/01 11:32:19 by jbadia           ###   ########.fr        #
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

OBJ_DIR	= obj 
SRC_DIR	= srcs
HDR	= libft.h
NAME = libft.a
CC	= gcc 
AR	= ar rcs
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -rf

SRC_C	=	srcs/ft_char/ft_isalnum.c srcs/ft_char/ft_isalpha.c \
			srcs/ft_char/ft_isascii.c srcs/ft_char/ft_isdigit.c \
			srcs/ft_char/ft_isprint.c srcs/ft_char/ft_tolower.c \
			srcs/ft_char/ft_toupper.c \
			srcs/ft_conv/ft_atoi.c srcs/ft_conv/ft_itoa.c\
			srcs/ft_list/ft_lstsize.c srcs/ft_list/ft_lstadd_front.c\
			srcs/ft_list/ft_lstadd_back.c srcs/ft_list/ft_lstlast.c\
			srcs/ft_list/ft_lstdelone.c srcs/ft_list/ft_lstclear.c\
			srcs/ft_list/ft_lstiter.c srcs/ft_list/ft_lstmap.c\
			srcs/ft_list/ft_lstnew.c\
			srcs/ft_mem/ft_bzero.c srcs/ft_mem/ft_calloc.c\
			srcs/ft_mem/ft_memccpy.c srcs/ft_mem/ft_memchr.c\
			srcs/ft_mem/ft_memcmp.c srcs/ft_mem/ft_memcpy.c\
			srcs/ft_mem/ft_memmove.c srcs/ft_mem/ft_memset.c\
			srcs/ft_put/ft_putchar_fd.c  srcs/ft_put/ft_putendl_fd.c\
			srcs/ft_put/ft_putnbr_fd.c srcs/ft_put/ft_putstr_fd.c\
			srcs/ft_str/ft_split.c srcs/ft_str/ft_strchr.c\
			srcs/ft_str/ft_strdup.c srcs/ft_str/ft_strjoin.c\
			srcs/ft_str/ft_strlcat.c srcs/ft_str/ft_strlcpy.c\
			srcs/ft_str/ft_strlen.c srcs/ft_str/ft_strmapi.c\
			srcs/ft_str/ft_strncmp.c srcs/ft_str/ft_strnstr.c\
			srcs/ft_str/ft_strrchr.c srcs/ft_str/ft_strtrim.c\
			srcs/ft_str/ft_substr.c srcs/ft_str/ft_strcmp.c\
			srcs/ft_str/ft_strcpy.c\
			srcs/ft_free/ft_free.c srcs/ft_free/ft_free_arrstr.c

OBJS	=	$(SRC_C:.c=.o)

.c.o:
	@${CC} ${CFLAGS} -c -I. $< -o $@

all	:		$(NAME)
	@echo "$(CBOLD)$(CITALIC)$(CVIOLET) LIBFT IS COMPILED $(NORMAL)"

$(NAME)	:	$(OBJS)
	@$(AR) $(NAME) $(OBJS)

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)
	@echo "$(CBOLD)$(CGREEN2) LIBFT IS CLEANED $(NORMAL)"

re : fclean all

.PHONY: all clean fclean re