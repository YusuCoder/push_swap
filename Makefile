RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m

NAME =

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCS =

SRC =
OBJ =

PRINTF = ./ryusupov_h/printf/libftprintf.a
LIBFT = ./ryusupov_h/libft/libft.h


all: $(NAME)
	@echo "$(GREEN) $(NAME)\n\n<---------------BUILT SUCCESSFULLY!--------------->\n"

bonus: $()
	@echo "$(GREEN) $(NAME)\n\n<---------------BONUS BUILT SUCCESSFULLY!--------------->\n"

$(PRINTF):
	@make -C ./ryusupov_h/printf

$(LIBFT):
	@make -C ./ryusupov_h/libftt

$(NAME): $(OBJ) $(PRINTF)
	@echo "$(GREEN) $(NAME)\n\n<---------------BUILDING MANDATORY OBJECTS--------------->\n"
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT)

%.o: %.c $(INCS)
	@echo "$(GREEN) $(NAME)\n\n<---------------Compiling--------------->\n"
$(CC) $(CFLAGS) -c $< -o $@

clean:
@echo "$(RED) \nCleaning ...............................................................\n"
$(MAKE) clean -C ./ryusupov_h/printf
$(MAKE) clean -C ./ryusupov_h/libftt
$(RM) $(SRC) $(OBJ) $(PRINTF) $(LIBFT)

fclean: clean
@echo "$(GREEN)\n<---------------All the object files and executables were successfully deleted!--------------->\n"
$(RM) $(NAME) $(OBJ)


re: fclean all
@echo "$(GREEN)<---------------All the object files were deleted and recompiled successfully!--------------->\n"

.PHONY: all re clean fclean bonus
