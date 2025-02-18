MAKEFLAGS += --no-print-directory
NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

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
		big_algorithm_utils.c\
		big_algorithm_utils_2.c\
		setup_digit_array.c\
		optimisation.c

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(NAME) successfully created! 🎉"

$(LIBFT): 
	@make -C $(LIBFT_DIR) --no-print-directory
	@touch $(LIBFT)  # Ajout d'un touch pour éviter le relink inutile

clean: 
	@echo "Cleaning object files..."
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
