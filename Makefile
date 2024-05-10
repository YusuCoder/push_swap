RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m

NAME = push_swap

LIBFT_DIR = ./ryusupov_h/libftt/
PRINTF_DIR = ./ryusupov_h/printf/
SRC_DIR := initialization rules input_error_ckeck sorting

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC := $(SRC_INIT) $(SRC_RULES) $(SRC_INPUT_CHECK) $(SRC_SORTING)
OBJ = $(SRC:.c=.o)


LIBFT = $(LIBFT_DIR)libft.a
PRINTF = $(PRINTF_DIR)libftprintf.a

INCS = -I ./ryusupov_h/

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

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)
	$(ANIMATE_WELCOME)

$(LIBFT):
@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	$(ANIMATE_PROCESSING)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re

FRAMES := 	"ss██╗sssssssssss██████╗s██╗sss██╗███████╗██╗ss██╗ssssssss███████╗██╗ssss██╗s█████╗s██████╗ssssssssssss██╗ss"\
			"s██╔╝sssssssssss██╔══██╗██║sss██║██╔════╝██║ss██║ssssssss██╔════╝██║ssss██║██╔══██╗██╔══██╗sssssssssss╚██╗s"\
			"██╔╝█████╗█████╗██████╔╝██║sss██║███████╗███████║ssssssss███████╗██║s█╗s██║███████║██████╔╝█████╗█████╗╚██╗"\
			"╚██╗╚════╝╚════╝██╔═══╝s██║sss██║╚════██║██╔══██║ssssssss╚════██║██║███╗██║██╔══██║██╔═══╝s╚════╝╚════╝██╔╝"\
			"s╚██╗sssssssssss██║sssss╚██████╔╝███████║██║ss██║███████╗███████║╚███╔███╔╝██║ss██║██║ssssssssssssssss██╔╝s"\
			"ss╚═╝sssssssssss╚═╝ssssss╚═════╝s╚══════╝╚═╝ss╚═╝╚══════╝╚══════╝s╚══╝╚══╝s╚═╝ss╚═╝╚═╝ssssssssssssssss╚═╝ss"\
			"sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"

