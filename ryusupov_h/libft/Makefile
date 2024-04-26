# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 20:08:19 by ryusupov          #+#    #+#              #
#    Updated: 2024/04/26 14:36:10 by ryusupov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRC = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_substr.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_realloc.c
OBJ = $(SRC:.c=.o)

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

INCS = ../ryusupov.h
RM = rm -f

all: $(NAME)
	@echo "$(GREEN)$(NAME) \n\n<---------------------------BUILT SUCCESSFULLY!--------------------------->\n"

$(NAME): $(OBJ)
	@echo "$(GREEN)\n<---------------------------BUILDING MANDATORY OBJECTS--------------------------->\n"
	$(AR) $@ $^

bonus: $(NAME) $(BONUS_OBJ)
	@echo "$(GREEN)\n<---------------------------Building bonus objects--------------------------->\n"
	$(AR) $(NAME) $(BONUS_OBJ)


%.o: %.c $(INCS)
	@echo "$(YELLOW)\n<---------------------------Compiling--------------------------->"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED) \nCleaning ........................................................................................\n"
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)
	@echo "$(GREEN)\n<---------------------------All the object files was successfully deleted!--------------------------->\n"

re: fclean all
	@echo "$(GREEN)<---------------------------All the object files was deleted and recompiled successfully!--------------------------->\n"

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
