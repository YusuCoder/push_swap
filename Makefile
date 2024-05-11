RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m

NAME = push_swap

INIT_PATH = ./initialization
ERROR_PATH = ./input_error_check
RULE_PATH = ./rules
SORT_PATH = ./sorting
OBJ_PATH = ./obj

LIBFT_PATH = ./ryusupov_h/libftt
LIBFTPRINTF_PATH = ./ryusupov_h/printf

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -g

INIT_SRC = $(INIT_PATH)/indexing.c \
           $(INIT_PATH)/positions.c \
           $(INIT_PATH)/push_swap.c \
           $(INIT_PATH)/stacks.c \
		   $(INIT_PATH)/check.c \
		   $(INIT_PATH)/helper_functions.c

RULE_SRC = $(RULE_PATH)/rev_rotates.c \
           $(RULE_PATH)/rotates.c \
           $(RULE_PATH)/swaps.c

SORT_SRC = $(SORT_PATH)/actions.c \
           $(SORT_PATH)/costs.c \
           $(SORT_PATH)/huge_sort.c \
           $(SORT_PATH)/pushes.c \
           $(SORT_PATH)/sorting.c

MAIN_SRC = main.c

INIT_OBJ = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(INIT_SRC)))
RULE_OBJ = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(RULE_SRC)))
SORT_OBJ = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(SORT_SRC)))
MAIN_OBJ = $(OBJ_PATH)/main.o

LIBFT = $(LIBFT_PATH)/libft.a
LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a

 define ANIMATE_WELCOME
     @printf "\n\033[1;32mProcessing"
     @sleep 0.1
     @for i in {1..10}; do \
         printf "."; \
         sleep 0.2; \
     done
     @printf "\033[0m\n\n\n"
     @sleep 0.5
     @for frame in $(FRAMES); do \
         printf "\x1b[35m%s\n\033[0m" $$frame; \
         sleep 0.1; \
     done
     @echo
 endef

 define ANIMATE_PROCESSING
     @printf "\n\033[1;31mCleaning"
     @sleep 0.5
     @for i in {1..10}; do \
         printf "."; \
         sleep 0.1; \
     done
     @printf "\033[0m\n\n"
 endef

all: $(NAME)

$(NAME): $(MAIN_OBJ) $(INIT_OBJ) $(RULE_OBJ) $(SORT_OBJ) $(LIBFT) $(LIBFTPRINTF)
	@$(CC) $(CFLAGS) $^ -o $@
	$(ANIMATE_WELCOME)

$(OBJ_PATH)/%.o: $(INIT_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/%.o: $(RULE_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/%.o: $(SORT_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/main.o: $(MAIN_SRC) | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/rev_rotate.o: $(RULE_PATH)/rev_rotate.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(LIBFTPRINTF):
	@$(MAKE) -C $(LIBFTPRINTF_PATH)

clean:
	@$(RM) $(OBJ_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(LIBFTPRINTF_PATH) clean
	$(ANIMATE_PROCESSING)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(LIBFTPRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re

FRAMES := 	"ss██╗sssssssssss██████╗s██╗sss██╗███████╗██╗ss██╗ssssssss███████╗██╗ssss██╗s█████╗s██████╗ssssssssssss██╗ss"\
			"s██╔╝sssssssssss██╔══██╗██║sss██║██╔════╝██║ss██║ssssssss██╔════╝██║ssss██║██╔══██╗██╔══██╗sssssssssss╚██╗s"\
			"██╔╝█████╗█████╗██████╔╝██║sss██║███████╗███████║ssssssss███████╗██║s█╗s██║███████║██████╔╝█████╗█████╗╚██╗"\
			"╚██╗╚════╝╚════╝██╔═══╝s██║sss██║╚════██║██╔══██║ssssssss╚════██║██║███╗██║██╔══██║██╔═══╝s╚════╝╚════╝██╔╝"\
			"s╚██╗sssssssssss██║sssss╚██████╔╝███████║██║ss██║███████╗███████║╚███╔███╔╝██║ss██║██║ssssssssssssssss██╔╝s"\
			"ss╚═╝sssssssssss╚═╝ssssss╚═════╝s╚══════╝╚═╝ss╚═╝╚══════╝╚══════╝s╚══╝╚══╝s╚═╝ss╚═╝╚═╝ssssssssssssssss╚═╝ss"\
			"sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"
