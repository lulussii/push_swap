MAKEFLAGS += --no-print-directory
NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRCS_DIR = src
BONUS_DIR = bonus
OBJS_DIR = objs
BONUS_OBJS_DIR = objs_bonus

SRCS =	$(SRCS_DIR)/big_algorithm_utils.c\
		$(SRCS_DIR)/big_algorithm_utils_2.c\
		$(SRCS_DIR)/big_algorithm.c\
		$(SRCS_DIR)/check_errors.c\
		$(SRCS_DIR)/initialisation_stack.c\
		$(SRCS_DIR)/instruction_push.c\
		$(SRCS_DIR)/instruction_rotate.c\
		$(SRCS_DIR)/instruction_reverse_rotate.c\
		$(SRCS_DIR)/instruction_swap.c\
		$(SRCS_DIR)/main.c\
		$(SRCS_DIR)/mid_algorithm.c\
		$(SRCS_DIR)/min_and_max.c\
		$(SRCS_DIR)/optimisation.c\
		$(SRCS_DIR)/optimisation_2.c\
		$(SRCS_DIR)/setup_digit_array.c\
		$(SRCS_DIR)/small_algorithm.c

BONUS_SRCS =	$(BONUS_DIR)/checker.c\
				$(BONUS_DIR)/initialisation_stack.c\
				$(BONUS_DIR)/checker_utils.c\
				$(BONUS_DIR)/check_errors.c\
				$(BONUS_DIR)/instruction_push.c\
				$(BONUS_DIR)/instruction_rotate.c\
				$(BONUS_DIR)/instruction_reverse_rotate.c\
				$(BONUS_DIR)/instruction_swap.c\

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS_OBJS := $(patsubst $(BONUS_DIR)/%, $(BONUS_OBJS_DIR)/%, $(BONUS_OBJS))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJS_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(NAME) successfully created! 🎉"

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	@echo "Compiling $(BONUS_NAME)..."
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)
	@echo "$(BONUS_NAME) successfully created! 🎉"

$(LIBFT): 
	@make -C $(LIBFT_DIR) --no-print-directory
	@touch $(LIBFT) 

bonus: $(BONUS_NAME)

clean: 
	@echo "Cleaning object files..."
	@rm -rf $(OBJS_DIR) $(BONUS_OBJS_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Removing $(NAME) and $(BONUS_NAME)..."
	@rm -f $(NAME) $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
