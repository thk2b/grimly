NAME = libft.test
LIBFT = ../libft.a

LIBFT_SRCS = ../srcs
SRCS =\
	test_llist.c\
	test_hm.c\
	test_queue.c\
	test_pq.c\
	main.c
OBJS = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I ../includes/

all: $(NAME)

$(LIBFT):
	make -C ../

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(OBJS) -o $(NAME) -g

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@ -g

clean:
	rm -f $(OBJS)
	make clean -C ../

fclean: clean
	rm -f $(NAME)
	make fclean -C ../

re: fclean all
