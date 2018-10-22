NAME = grimly
LIBFT = libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I libft/includes
HEAD = grimly.h

SRCS = \
	main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
