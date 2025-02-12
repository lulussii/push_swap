MAKEFLAGS += --no-print-directory
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -g

SRCS = 	main.c\
		check_errors.c\
		instruction_push.c\
		instruction_rotate.c\
		instruction_reverse_rotate.c\
		instruction_swap.c\
		initialisation_stack.c\
		small_algorithm.c\
		mid_algorithm.c\
		min_and_max.c\
		big_algorithm.c\
		optimisation.c

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
OBJS_DIR = objs

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(NAME) successfully created! 🎉"

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean: 
	@echo "Cleaning object files..."
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT)
