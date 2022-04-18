# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartine <omartine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 13:33:15 by omartine          #+#    #+#              #
#    Updated: 2022/04/18 13:33:18 by omartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_S = server
NAME_C = client

S_SERVER = server.c utils/ft_atoi.c utils/ft_itoa.c utils/ft_strlen.c \
			utils/str_cpy.c

S_CLIENT = client.c utils/ft_atoi.c utils/ft_itoa.c utils/ft_strlen.c \
			utils/str_cpy.c utils/client_utils.c

OBJS_SERVER = $(S_SERVER:.c=.o)

OBJS_CLIENT = $(S_CLIENT:.c=.o)

BONUS_O = $(SRCS_BONUS:.c=.o)

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -fsanitize=address -g3
MAKE			= make

ALL:			$(NAME_C) $(NAME_S)

SERVER:			$(NAME_S)

$(NAME_S):		$(OBJS_SERVER)
					$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_S)

CLIENT:			$(NAME_C)

$(NAME_C):		$(OBJS_CLIENT)
					$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_C)

clean:
				$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean:			clean
				$(RM) $(NAME_C) $(NAME_S)

re:				fclean $(NAME_S) $(NAME_C)

.PHONY:			all clean fclean re bonus client server
