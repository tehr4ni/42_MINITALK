NAME		= minitalk
CC		= cc
CFLAGS		= -Wall -Werror -Wextra

LIBFTNAME	= libft.a
LIBFTDIR	= ./libft

SRCS		= client.c server.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTDIR)/$(LIBFTNAME)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTDIR)/$(LIBFTNAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re:	fclean all
