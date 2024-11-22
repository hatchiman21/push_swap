LIBFT_DIR = ./libft
OP_DIR = ./operations
SRC_DR = ./src
LIBFT = $(LIBFT_DIR)/libftprintf.a

OP_SRC = push.c swap.c rotate.c reverse_rotate.c 
OP_SRC:= $(addprefix $(OP_DIR)/, $(OP_SRC))

SRC = main.c ft_sort_small.c ft_sort.c stack_check.c error_check.c \
		get_functions.c grab_stack.c post_processing.c postion.c
SRC:= $(addprefix $(SRC_DR)/, $(SRC))
SRCS = $(OP_SRC) $(SRC)
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -I. -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
