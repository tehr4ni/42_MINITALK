CC		= cc
CFLAGS		= -Wall -Werror -Wextra
LIBFT_A		= ./libft/libft.a
LIBFTDIR	= ./libft
PRINTF_A	= ./printf/libftprintf.a
PRINTFDIR	= ./printf

SRCS		= client.c server.c
LINK_CMD	= $(CC) $(CFLAGS) -o $@ $< $(LIBFT_A) $(PRINTF_A)

OBJS		= $(SRCS:.c=.o)

all:	server client

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	make -s -C $(LIBFTDIR)

$(PRINTF_A):
	make -s -C $(PRINTFDIR)

server:	server.o $(LIBFT_A) $(PRINTF_A)
	$(LINK_CMD)

client:	client.o $(LIBFT_A) $(PRINTF_A)
	$(LINK_CMD)

clean:
	@rm -f $(OBJS)
	make -C $(LIBFTDIR) clean
	make -C $(PRINTFDIR) clean

fclean:	clean
	@rm -f server client
	make -C $(LIBFTDIR) fclean
	make -C $(PRINTFDIR) fclean

re:	fclean all

.PHONY:	all clean fclean re
