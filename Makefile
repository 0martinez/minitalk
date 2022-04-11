NAME_S = server
NAME_C = client
CC						= gcc
RM						= rm -rf
CFLAGS					= -Wall -Wextra -Werror
MAKE					= make


S_SERVER =	server.c utils/ft_atoi.c utils/ft_itoa.c utils/ft_strlen.c \
        	utils/str_cpy.c

S_CLIENT =	client.c utils/ft_atoi.c utils/ft_itoa.c utils/ft_strlen.c \
			utils/str_cpy.c

OBJS_SERVER = $(S_SERVER:.c=.o)

OBJS_CLIENT = $(S_CLIENT:.c=.o)


SERVER:					$(NAME_S)

$(NAME_S):				$(OBJS_SERVER)
                                        $(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_S)

CLIENT:                 $(NAME_C)

$(NAME_C):				$(OBJS_CLIENT)
                                    	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_C)

clean:
                                $(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean:                 clean
                                $(RM) $(NAME_C) $(NAME_S)

re:                             fclean $(NAME_S) $(NAME_C)

.PHONY:                 all clean fclean re bonus client server
