NAME = grimly
LIBFT = libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I libft/includes
HEAD = grimly.h

SRCS = \
	parse_metadata.c\
	tile_map_free.c\
	read_tile_map.c\
	print_tile_map.c\
	value_map.c\
	point.c\
	bfs.c\
	render_path.c\
	grimly.c\
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
